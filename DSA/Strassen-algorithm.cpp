#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Matrix;

Matrix add(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix result(n, vector<ll>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

Matrix subtract(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix result(n, vector<ll>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

Matrix strassen(const Matrix &A, const Matrix &B) {
    int n = A.size();
    if (n == 1) {
        return Matrix(1, vector<ll>(1, A[0][0] * B[0][0]));
    }

    int k = n / 2;
    Matrix A11(k, vector<ll>(k)), A12(k, vector<ll>(k)), A21(k, vector<ll>(k)), A22(k, vector<ll>(k));
    Matrix B11(k, vector<ll>(k)), B12(k, vector<ll>(k)), B21(k, vector<ll>(k)), B22(k, vector<ll>(k));

    for (int i = 0; i < k; ++i)
        for (int j = 0; j < k; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }

    Matrix M1 = strassen(add(A11, A22), add(B11, B22));
    Matrix M2 = strassen(add(A21, A22), B11);
    Matrix M3 = strassen(A11, subtract(B12, B22));
    Matrix M4 = strassen(A22, subtract(B21, B11));
    Matrix M5 = strassen(add(A11, A12), B22);
    Matrix M6 = strassen(subtract(A21, A11), add(B11, B12));
    Matrix M7 = strassen(subtract(A12, A22), add(B21, B22));

    Matrix C11 = add(subtract(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(subtract(add(M1, M3), M2), M6);

    Matrix C(n, vector<ll>(n));
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < k; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }

    return C;
}

int nextPowerOfTwo(int n) {
    int power = 1;
    while (power < n)
        power <<= 1;
    return power;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b != c) {
        cout << "Matrix multiplication not possible";
        return 0;
    }

    vector<ll> dataA(a * b), dataB(c * d);
    for (int i = 0; i < a * b; ++i) cin >> dataA[i];
    for (int i = 0; i < c * d; ++i) cin >> dataB[i];

    Matrix A(a, vector<ll>(b));
    Matrix B(c, vector<ll>(d));
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            A[i][j] = dataA[i * b + j];
    for (int i = 0; i < c; ++i)
        for (int j = 0; j < d; ++j)
            B[i][j] = dataB[i * d + j];

    int max_dim = max({a, b, c, d});
    int n = nextPowerOfTwo(max_dim);

    Matrix newA(n, vector<ll>(n, 0));
    Matrix newB(n, vector<ll>(n, 0));

    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            newA[i][j] = A[i][j];
    for (int i = 0; i < c; ++i)
        for (int j = 0; j < d; ++j)
            newB[i][j] = B[i][j];

    Matrix C = strassen(newA, newB);

    bool first = true;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < d; ++j) {
            if (!first) cout << " ";
            cout << C[i][j];
            first = false;
        }
    }
    return 0;
}
