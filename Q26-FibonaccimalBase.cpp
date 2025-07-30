#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    vector<int> Fibonacci(40, 0);
    Fibonacci[1] = 1;

    // Tính trước dãy Fibonacci từ F(0) đến F(39)
    for (int i = 2; i < 40; ++i) {
        Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
    }

    cin >> N;

    while (N--) {
        int num;
        bool flag = false;

        cin >> num;
        cout << num << " = ";

        // In biểu diễn Zeckendorf (không có hai số Fibonacci liên tiếp)
        for (int i = 39; i >= 2; --i) {
            if (num >= Fibonacci[i]) {
                num -= Fibonacci[i];
                flag = true;
                cout << "1";
            } else if (flag) {
                cout << "0";
            }
        }

        cout << " (fib)" << endl;
    }

    return 0;
}
