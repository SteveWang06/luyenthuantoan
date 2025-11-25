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