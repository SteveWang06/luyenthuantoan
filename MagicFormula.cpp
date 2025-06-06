// You are given a quadratic function,
// f(x) = ax2 + bx + c
// You are also given a divisor d and a limit L. How
// many of the function values f(0), f(1), . . . , f(L) are
// divisible by d?
// Input
// Input consists of a number of test cases. Each test
// case consists of a single line containing the numbers
// a b c d L (−1000 ≤ a, b, c ≤ 1000, 1 < d < 1000000,
// 0 ≤ L < 1000).
// Input is terminated by a line containing ‘0 0 0 0 0’ which should not be processed.
// Output
// Print the answer for each test case (the number of function values f(0), f(1), . . . , f(L) divisible by d)
// on a separate line.
// Sample Input
// 0 0 10 5 100
// 0 0 10 6 100
// 1 2 3 4 5
// 1 2 3 3 5
// 0 0 0 0 0
// Sample Output
// 101
// 0
// 0
// 4



// Bạn được cho một hàm bậc hai:
//   f(x) = ax² + bx + c

// Bạn cũng được cho một số chia d và một giới hạn L.
// Hãy xác định có bao nhiêu giá trị của hàm số:
//   f(0), f(1), ..., f(L)
// chia hết cho d.

// Dữ liệu vào (Input)
// Gồm nhiều dòng, mỗi dòng là một bộ test:

// Mỗi dòng chứa 5 số nguyên: a b c d L
//   với:
//     −1000 ≤ a, b, c ≤ 1000
//     1 < d < 1.000.000
//     0 ≤ L < 1000

// Dòng cuối cùng là: 0 0 0 0 0
//   (kết thúc chương trình, không xử lý dòng này)

// Dữ liệu ra (Output)
// Với mỗi bộ test, in ra một dòng chứa số lượng giá trị f(x) (với x = 0 đến L) chia hết cho d.


#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, L, count;

    cin >> a >> b >> c >> d >> L;
    while (a != 0 || b != 0 || c != 0 || d != 0 || L != 0) {
        count = 0;
        for (int i = 0; i <= L; ++i) {
            if ((a * i * i + b * i + c) % d == 0)
                ++count;
        }
        cout << count << endl;
        cin >> a >> b >> c >> d >> L;
    }

    return 0;
}