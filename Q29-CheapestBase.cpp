#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testCases;
    cin >> testCases;

    for (int caseNumber = 1; caseNumber <= testCases; caseNumber++) {
        if (caseNumber > 1) cout << "\n";

        // costMap[i] là chi phí in ký tự thứ i (từ '0' đến 'Z')
        map<int, int> costMap;
        int charCost;
        for (int i = 0; i < 36; i++) {
            cin >> charCost;
            costMap[i] = charCost;
        }

        cout << "Case " << caseNumber << ":\n";

        int queryCount;
        cin >> queryCount;

        while (queryCount--) {
            int number;
            cin >> number;

            cout << "Cheapest base(s) for number " << number << ":";

            int minCost = 0x7FFFFFFF;
            map<int, int> baseCostMap;

            // Thử từng cơ số từ 2 đến 36
            for (int base = 2; base <= 36; base++) {
                int n = number;
                int totalCost = 0;

                // Chuyển số sang hệ cơ số `base` và tính tổng chi phí in
                while (n > 0) {
                    int digit = n % base;
                    totalCost += costMap[digit];
                    n /= base;
                }

                baseCostMap[base] = totalCost;
                minCost = min(minCost, totalCost);
            }

            // In ra các cơ số có chi phí nhỏ nhất
            for (int base = 2; base <= 36; base++) {
                if (baseCostMap[base] == minCost) {
                    cout << " " << base;
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
