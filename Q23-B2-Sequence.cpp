#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Hàm kiểm tra xem một dãy có phải là B2-Sequence hay không
bool isB2Sequence(const vector<int>& sequence) {
    int n = sequence.size();

    // Kiểm tra điều kiện tăng dần nghiêm ngặt: b1 < b2 < b3 < ...
    for (int i = 1; i < n; ++i) {
        if (sequence[i] <= sequence[i - 1]) {
            return false;
        }
    }

    // Kiểm tra tính duy nhất của tất cả các tổng: bi + bj (với i ≤ j)
    unordered_set<int> uniqueSums;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int sum = sequence[i] + sequence[j];
            if (uniqueSums.count(sum)) {
                return false; // Tổng bị trùng
            }
            uniqueSums.insert(sum);
        }
    }

    return true;
}

int main() {
    int n, testCase = 1;

    // Đọc từng test case cho đến khi gặp EOF
    while (cin >> n) {
        vector<int> sequence(n);

        // Đọc dãy số
        for (int i = 0; i < n; ++i) {
            cin >> sequence[i];
        }

        // Kiểm tra và in kết quả
        cout << "Case #" << testCase++ << ": ";
        if (isB2Sequence(sequence)) {
            cout << "It is a B2-Sequence.\n";
        } else {
            cout << "It is not a B2-Sequence.\n";
        }

        cout << '\n'; // In dòng trống sau mỗi test case
    }

    return 0;
}














#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isSequence(const vector<int> sequence) {

    int n = sequence.size();

    for (size_t i = 1; i < n; i++)
    {
       
        if (sequence[i] <= sequence[i-1])
        {
            return false;
        }
         
    }

    unordered_set<int> uniqueSums;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i; j < n; j++)
        {
            int sum = sequence[i] + sequence[j];
            if (uniqueSums.count(sum))
            {
                return false;
            }
            uniqueSums.insert(sum);
        }
        
    }

    return true;
}

int main() {

    int n;
    int caseNum = 1;

    

    while (cin >> n)
    {
        vector<int> sequence(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> sequence[i];
        }

        cout << "Case #" << caseNum++ << ":";
        if (isSequence(sequence))
        {
            cout << " It is a B2-Sequence." << "\n";
        }else
        {
            cout << " It is not a B2-Sequence." << "\n";
        }

        cout << "\n";
    }

    

    return 0;
}



















