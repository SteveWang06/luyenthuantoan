#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string inputLine;
    int xValue; // Giá trị của x tại đó đạo hàm được tính

    while (getline(cin, inputLine)) {
        xValue = stoi(inputLine); // Đọc giá trị x từ dòng đầu tiên

        if (!getline(cin, inputLine)) break; // Đọc dòng chứa hệ số của đa thức

        istringstream coefficientStream(inputLine);

        vector<int> polynomialCoefficients; // Lưu các hệ số của đa thức
        int coefficient;

        // Đọc từng hệ số từ dòng và lưu vào vector
        while (coefficientStream >> coefficient) {
            polynomialCoefficients.push_back(coefficient);
        }

        int polynomialDegree = polynomialCoefficients.size() - 1; // Bậc của đa thức
        long long derivativeValue = 0; // Giá trị của đạo hàm tại x

        // Tính đạo hàm theo công thức: aᵢ * (n - i) * x^(n - i - 1)
        for (int i = 0; i < polynomialDegree; ++i) {
            int currentCoefficient = polynomialCoefficients[i];
            derivativeValue += static_cast<long long>(currentCoefficient) * (polynomialDegree - i) * pow(xValue, polynomialDegree - i - 1);
        }

        cout << derivativeValue << endl;
    }

    return 0;
}
