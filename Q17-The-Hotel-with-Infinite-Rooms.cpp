#include <iostream>

using namespace std;

int main() {
    long long S, D;
    while (cin >> S >> D) {
        long long currentGroup = S;
        long long totalDays = 0;

        // Tăng dần nhóm cho đến khi tổng ngày >= D
        while (totalDays < D) {
            totalDays += currentGroup;
            currentGroup++;
        }

        // Nhóm hiện tại là người cuối cùng đã thêm -> phải -1
        cout << currentGroup - 1 << endl;
    }

    return 0;
}
