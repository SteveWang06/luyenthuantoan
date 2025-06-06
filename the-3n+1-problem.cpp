// Problems in Computer Science are often classified as belonging to a certain class of problems (e.g.,
// NP, Unsolvable, Recursive). In this problem you will be analyzing a property of an algorithm whose
// classification is not known for all possible inputs.
// Consider the following algorithm:
// 1. input n
// 2. print n
// 3. if n = 1 then STOP
// 4. if n is odd then n ←− 3n + 1
// 5. else n ←− n/2
// 6. GOTO 2
// Given the input 22, the following sequence of numbers will be printed
// 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
// It is conjectured that the algorithm above will terminate (when a 1 is printed) for any integral input
// value. Despite the simplicity of the algorithm, it is unknown whether this conjecture is true. It has
// been verified, however, for all integers n such that 0 < n < 1, 000, 000 (and, in fact, for many more
// numbers than this.)
// Given an input n, it is possible to determine the number of numbers printed before and including
// the 1 is printed. For a given n this is called the cycle-length of n. In the example above, the cycle
// length of 22 is 16.
// For any two numbers i and j you are to determine the maximum cycle length over all numbers
// between and including both i and j.
// Input
// The input will consist of a series of pairs of integers i and j, one pair of integers per line. All integers
// will be less than 10,000 and greater than 0.
// You should process all pairs of integers and for each pair determine the maximum cycle length over
// all integers between and including i and j.
// You can assume that no operation overflows a 32-bit integer.
// Output
// For each pair of input integers i and j you should output i, j, and the maximum cycle length for
// integers between and including i and j. These three numbers should be separated by at least one space
// with all three numbers on one line and with one line of output for each line of input. The integers i
// and j must appear in the output in the same order in which they appeared in the input and should be
// followed by the maximum cycle length (on the same line).
// Sample Input
// 1 10
// 100 200
// 201 210
// 900 1000
// Sample Output
// 1 10 20
// 100 200 125
// 201 210 89
// 900 1000 174




// Các bài toán trong Khoa học máy tính thường được phân loại là thuộc về một lớp bài toán nhất định (ví dụ:
// NP, Không giải được, Đệ quy). Trong bài toán này, bạn sẽ phân tích một thuộc tính của một thuật toán mà
// phân loại của nó không được biết đến đối với tất cả các đầu vào có thể.
// Xem xét thuật toán sau:
// 1. input n
// 2. print n
// 3. if n = 1 then STOP
// 4. if n is odd then n ←− 3n + 1
// 5. else n ←− n/2
// 6. GOTO 2
// Với đầu vào là 22, chuỗi số sau sẽ được in ra
// 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
// Người ta cho rằng thuật toán trên sẽ kết thúc (khi in ra số 1) đối với bất kỳ giá trị đầu vào nguyên nào
//. Mặc dù thuật toán rất đơn giản, nhưng người ta vẫn chưa biết liệu phỏng đoán này có đúng hay không. Tuy nhiên, điều này đã được
// xác minh đối với mọi số nguyên n sao cho 0 < n < 1.000.000 (và trên thực tế, đối với nhiều số
// hơn thế này.)
// Với đầu vào n, có thể xác định số lượng số được in trước và bao gồm
// số 1 được in. Đối với một n cho trước, đây được gọi là độ dài chu kỳ của n. Trong ví dụ trên, độ dài chu kỳ
// của 22 là 16.
// Đối với bất kỳ hai số i và j nào, bạn phải xác định độ dài chu kỳ tối đa trên tất cả các số
// nằm giữa và bao gồm cả i và j.
// Đầu vào
// Đầu vào sẽ bao gồm một chuỗi các cặp số nguyên i và j, mỗi cặp một dòng. Tất cả các số nguyên
// sẽ nhỏ hơn 10.000 và lớn hơn 0.
// Bạn nên xử lý tất cả các cặp số nguyên và đối với mỗi cặp, hãy xác định độ dài chu kỳ tối đa trên
// tất cả các số nguyên nằm giữa và bao gồm i và j.
// Bạn có thể cho rằng không có phép toán nào tràn số nguyên 32 bit.
// Đầu ra
// Đối với mỗi cặp số nguyên đầu vào i và j, bạn nên đầu ra i, j và độ dài chu kỳ tối đa cho
// các số nguyên nằm giữa và bao gồm i và j. Ba số này phải được phân tách bằng ít nhất một khoảng trắng
// với cả ba số trên một dòng và với một dòng đầu ra cho mỗi dòng đầu vào. Các số nguyên i
// và j phải xuất hiện trong đầu ra theo cùng thứ tự mà chúng xuất hiện trong đầu vào và phải
// theo sau là độ dài chu kỳ tối đa (trên cùng một dòng).
// Đầu vào mẫu
// 1 10
// 100 200
// 201 210
// 900 1000
// Đầu ra mẫu
// 1 10 20
// 100 200 125
// 201 210 89
// 900 1000 174


#include <iostream>
using namespace std;

// Tính độ dài chu trình của một số n
int cycle_length(int n) {
    int count = 1;
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        count++;
    }
    return count;
}

int main() {
    int i, j;
    while (cin >> i >> j) {
        int start = min(i, j);
        int end = max(i, j);
        int max_cycle = 0;

        for (int k = start; k <= end; ++k) {
            int len = cycle_length(k);
            if (len > max_cycle)
                max_cycle = len;
        }

        cout << i << " " << j << " " << max_cycle << endl;
    }

    return 0;
}

