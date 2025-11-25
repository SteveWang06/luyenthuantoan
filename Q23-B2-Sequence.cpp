
// 11063 B2-Sequence
// A B2-Sequence is a sequence of positive integers 1 ≤ b1 < b2 < b3. . . such that all pairwise sums bi + bj ,
// where i ≤ j, are different.
// Your task is to determine if a given sequence is a B2-Sequence or not.
// Input
// Each test case starts with 2 ≤ N ≤ 100, the number of elements in a sequence. Next line will have N
// integers, representing the value of each element in the sequence. Each element bi is an integer such that
// bi ≤ 10000. There is a blank line after each test case. The input is terminated by end of file (EOF).
// Output
// For each test case you must print the number of the test case, starting from 1, and a message indicating
// if the corresponding sequence it is a B2-Sequence or not. See the sample output below. After each test
// case you must print a blank line.
// Sample Input
// 4
// 1 2 4 8
// 4
// 3 7 10 14
// Sample Output
// Case #1: It is a B2-Sequence.
// Case #2: It is not a B2-Sequence.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, Case = 1;
    while (cin >> n) {
        vector<int> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];

        bool flag = true;

        // 1) kiểm tra dãy dương và strictly increasing
        if (n <= 0) flag = false;
        for (int i = 0; i < n && flag; ++i) {
            if (b[i] < 1) flag = false;                // phải là số dương
            if (i > 0 && b[i] <= b[i-1]) flag = false; // phải tăng chặt
        }

        // 2) kiểm tra các tổng bi + bj (i <= j) là duy nhất
        if (flag) {
            unordered_set<int> seen;
            seen.reserve(n * (n + 1) / 2 * 2);
            for (int i = 0; i < n && flag; ++i) {
                for (int j = i; j < n; ++j) {
                    int s = b[i] + b[j];
                    if (seen.find(s) != seen.end()) {
                        flag = false;
                        break;
                    }
                    seen.insert(s);
                }
            }
        }

        if (flag) cout << "Case #" << Case++ << ": It is a B2-Sequence.\n\n";
        else cout << "Case #" << Case++ << ": It is not a B2-Sequence.\n\n";
    }

    return 0;
}