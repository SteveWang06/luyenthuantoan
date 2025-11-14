#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    int x;
    vector<int> v;

    while (cin >> x) {
        getline(cin, s); // Đọc phần còn lại của dòng
        getline(cin, s); // Đọc dòng chứa các hệ số
        stringstream ss(s);
        v.clear();

        // Đọc các hệ số vào vector
        while (ss >> s) {
            v.push_back(stoi(s));
        }

        // Loại bỏ hệ số tự do (hệ số cuối cùng)
        v.pop_back();

        // Đảo ngược vector để tính từ bậc thấp đến bậc cao
        reverse(v.begin(), v.end());

        // Tính giá trị đạo hàm
        long long mul = 1; // Giá trị x^i
        int ans = 0;       // Tổng giá trị đạo hàm
        for (int i = 0; i < v.size(); i++) {
            ans += v[i] * (i + 1) * mul; // Tính hạng tử
            mul *= x;                    // Cập nhật x^i
        }

        // In kết quả
        cout << ans << "\n";
    }

    return 0;
}