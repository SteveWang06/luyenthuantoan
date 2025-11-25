#include <iostream>
using namespace std;
 
int main() {
    int sum, mx, temp;
    string s;
    while (getline(cin, s)){
        sum = 0;
        mx = 1;
        int i;
        for (i = 0; i < s.size(); i++) {
            // Chuyển ký tự thành giá trị số
            if (s[i] >= '0' && s[i] <= '9') temp = s[i] - '0';        // 0-9
            else if (s[i] >= 'A' && s[i] <= 'Z') temp = s[i] - 'A' + 10;  // 10-35
            else if (s[i] >= 'a' && s[i] <= 'z') temp = s[i] - 'a' + 36;  // 36-61
            
            mx = max(mx, temp);  // Tìm chữ số lớn nhất
            sum += temp;         // Tổng các chữ số
        }
 
        for (i = mx; i < 62; i++){
            if (!(sum % i)) {      // Kiểm tra sum chia hết cho (N-1)
                cout << i + 1 << "\n";  // N = i + 1
                break;
            }
        }  // i đại diện cho (N-1)
            
 
        if (i == 62)
            cout << "such number is impossible!\n";
    }
    return 0;
}