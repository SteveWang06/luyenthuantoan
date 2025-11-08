
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

        // Đếm tầng xuất xuất hiện của ký tự trong chuỗi a
        for (char c : a) {
            countA[c - 'a']++;
        }

        // Đếm tầng xuất xuất hiện của ký tự trong chuỗi b
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
