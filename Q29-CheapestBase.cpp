#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

// Hàm chuyển một số nguyên sang chuỗi biểu diễn trong hệ cơ số bất kỳ
string convertToBase(int number, int base) {
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (number == 0) return "0";

    string result = "";
    while (number > 0) {
        result = digits[number % base] + result;
        number /= base;
    }

    return result;
}

// Hàm tính tổng chi phí in số ở một cơ số, dựa trên bảng chi phí
int computeCost(const string& numberStr, const vector<int>& cost) {
    int total = 0;
    for (char c : numberStr) {
        if (isdigit(c)) {
            total += cost[c - '0'];
        } else {
            total += cost[c - 'A' + 10];
        }
    }
    return total;
}

// Tìm danh sách các cơ số có chi phí in nhỏ nhất
vector<int> findCheapestBases(int number, const vector<int>& cost) {
    int minCost = INT_MAX;
    vector<int> cheapest;

    for (int base = 2; base <= 36; ++base) {
        string converted = convertToBase(number, base);
        int currentCost = computeCost(converted, cost);

        if (currentCost < minCost) {
            minCost = currentCost;
            cheapest.clear();
            cheapest.push_back(base);
        } else if (currentCost == minCost) {
            cheapest.push_back(base);
        }
    }

    return cheapest;
}

int main() {
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        vector<int> cost(36);
        // Đọc 4 dòng, mỗi dòng 9 số = 36 ký tự
        for (int i = 0; i < 36; ++i) {
            cin >> cost[i];
        }

        int Q;
        cin >> Q;

        cout << "Case " << caseNum << ":\n";

        for (int i = 0; i < Q; ++i) {
            int N;
            cin >> N;

            vector<int> cheapest = findCheapestBases(N, cost);

            cout << "Cheapest base(s) for number " << N << ":";
            for (int b : cheapest) {
                cout << " " << b;
            }
            cout << "\n";
        }

        if (caseNum < T) {
            cout << "\n";
        }
    }

    return 0;
}
