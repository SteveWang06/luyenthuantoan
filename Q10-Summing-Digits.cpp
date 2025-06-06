// For a positive integer n, let f(n) denote the
// sum of the digits of n when represented in base
// 10. It is easy to see that the sequence of numbers n, f(n), f(f(n)), f(f(f(n))), . . . eventually
// becomes a single digit number that repeats forever. Let this single digit be denoted g(n).
// For example, consider n = 1234567892.
// Then:
// f(n) = 1+2+3+4+5+6+7+8+9+2 = 47
// f(f(n)) = 4 + 7 = 11
// f(f(f(n))) = 1 + 1 = 2
// Therefore, g(1234567892) = 2.
// Input
// Each line of input contains a single positive integer n at most 2,000,000,000. Input is terminated
// by n = 0 which should not be processed.
// Output
// For each such integer, you are to output a single
// line containing g(n).
// Sample Input
// 2
// 11
// 47
// 1234567892
// 0
// Sample Output
// 2
// 2
// 2
// 2


// Đối với một số nguyên dương n, hãy để f(n) là tổng các chữ số của n khi biểu diễn ở hệ cơ số 10. Dễ dàng nhận thấy rằng dãy số n, f(n), f(f(n)), f(f(f(n))), ... cuối cùng sẽ trở thành một chữ số duy nhất và lặp lại mãi mãi. Gọi chữ số duy nhất này là g(n).

// Ví dụ, xét n = 1234567892.
// Khi đó:

// f(n) = 1+2+3+4+5+6+7+8+9+2 = 47

// f(f(n)) = 4 + 7 = 11

// f(f(f(n))) = 1 + 1 = 2

// Vì vậy, g(1234567892) = 2.

// Dữ liệu vào
// Mỗi dòng của dữ liệu vào chứa một số nguyên dương n không quá 2.000.000.000. Dữ liệu kết thúc khi n = 0, dòng này không được xử lý.

// Dữ liệu ra
// Với mỗi số nguyên, bạn phải in ra một dòng duy nhất chứa g(n).

// Ví dụ dữ liệu vào
// 2  
// 11  
// 47  
// 1234567892  
// 0


// Ví dụ dữ liệu ra
// 2  
// 2  
// 2  
// 2





#include <iostream>
using namespace std;

// Hàm tính g(n) tối ưu bằng công thức
int g(int n) {
    if (n == 0) return 0;
    return 1 + (n - 1) % 9;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        cout << g(n) << endl;
    }
    return 0;
}
