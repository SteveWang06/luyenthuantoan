// Input file contains several lines of input. Consecutive two lines make a set of input. That means in the
// input file line 1 and 2 is a set of input, line 3 and 4 is a set of input and so on. The first line of a pair
// contains a and the second contains b. Each string is on a separate line and consists of at most 1000
// lowercase letters.
// Output
// For each set of input, output a line containing x. If several x satisfy the criteria above, choose the first
// one in alphabetical order.
// Sample Input
// pretty
// women
// walking
// down
// the
// street
// Sample Output
// e
// nw
// et

// Đề bài:

// Cho hai chuỗi ký tự thường, a và b. Hãy in ra chuỗi x dài nhất gồm các ký tự thường sao cho:

// Có một hoán vị của x là một tập con theo thứ tự (subsequence) của chuỗi a, và

// Có một hoán vị của x là một tập con theo thứ tự (subsequence) của chuỗi b.

// Dữ liệu vào:

// Tệp đầu vào gồm nhiều dòng. Mỗi hai dòng liên tiếp là một bộ dữ liệu đầu vào.
// Nghĩa là dòng 1 và dòng 2 là một bộ, dòng 3 và dòng 4 là bộ tiếp theo, v.v...

// Mỗi chuỗi nằm trên một dòng riêng biệt và gồm tối đa 1000 ký tự chữ thường.

// Dữ liệu ra:

// Với mỗi bộ dữ liệu đầu vào, hãy in ra một dòng chứa chuỗi x thoả mãn điều kiện trên.
// Nếu có nhiều chuỗi x thoả mãn, hãy chọn chuỗi nào có thứ tự từ điển nhỏ nhất (alphabetically first).


// Ví dụ Dữ liệu vào:
// pretty
// women
// walking
// down
// the
// street

// Ví dụ Dữ liệu ra:
// e
// nw
// et




#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    string a, b;
    while (getline(cin, a) && getline(cin, b)) {
        int countA[26] = {0};
        int countB[26] = {0};

        // Đếm ký tự trong chuỗi a
        for (char c : a) {
            countA[c - 'a']++;
        }

        // Đếm ký tự trong chuỗi b
        for (char c : b) {
            countB[c - 'a']++;
        }

        // In ra các ký tự chung theo thứ tự từ điển
        for (int i = 0; i < 26; ++i) {
            int common = min(countA[i], countB[i]);
            for (int j = 0; j < common; ++j) {
                cout << char(i + 'a');
            }
        }
        cout << endl;
    }
    return 0;
}































