#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n <= 0) {
            cout << "Not jolly\n";
            continue;
        }
        vector<int> d(n, 0); // Sử dụng vector thay cho mảng tĩnh
        int pre, now;
        cin >> pre;
        for (int i = 1; i < n; i++) {
            cin >> now;
            int diff = abs(now - pre);
            if (diff > 0 && diff < n) {
                d[diff]++;
            }
            pre = now;
        }
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (d[i] != 1) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    return 0;
}