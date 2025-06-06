// Children are taught to add multi-digit numbers from right-to-left one digit at a time. Many find the
// “carry” operation - in which a 1 is carried from one digit position to be added to the next - to be a
// significant challenge. Your job is to count the number of carry operations for each of a set of addition
// problems so that educators may assess their difficulty.
// Input
// Each line of input contains two unsigned integers less than 10 digits. The last line of input contains ‘0
// 0’.
// Output
// For each line of input except the last you should compute and print the number of carry operations
// that would result from adding the two numbers, in the format shown below.
// Sample Input
// 123 456
// 555 555
// 123 594
// 0 0
// Sample Output
// No carry operation.
// 3 carry operations.
// 1 carry operation.


// Trẻ em thường được dạy cách cộng các số nhiều chữ số từ phải sang trái, từng chữ số một.
// Nhiều em thấy phép "nhớ" – khi phải "nhớ 1" từ một vị trí sang vị trí tiếp theo – là một phần khó khăn.

// Nhiệm vụ của bạn là đếm số lần thực hiện phép "nhớ" trong mỗi phép cộng, để giáo viên có thể đánh giá mức độ khó của bài toán.

// Dữ liệu vào (Input)
// Mỗi dòng là hai số nguyên không âm ít hơn 10 chữ số.

// Dòng cuối cùng là: 0 0 (kết thúc, không xử lý dòng này).

// Dữ liệu ra (Output)
// Với mỗi dòng dữ liệu (trừ dòng cuối), in ra số lần thực hiện phép nhớ, theo định dạng:

// "No carry operation." nếu không có phép nhớ nào.

// "1 carry operation." nếu có đúng 1 phép nhớ.

// "x carry operations." nếu có từ 2 phép nhớ trở lên (x là số lần nhớ).



#include <iostream>
#include <cmath>    
using namespace std;

int main() {
    long long a, b;  
    while (cin >> a >> b) {  
        if (a == 0 && b == 0) {
            break;
        }
        int carry = 0;
        int carryCount = 0;
        while (a > 0 || b > 0) {
            int sum = a % 10 + b % 10 + carry;
            if (sum >= 10) {
                carry = 1;
                carryCount++;
            } else {
                carry = 0;
            }
            a /= 10;
            b /= 10;
        }
        if (carryCount == 0) {
            cout << "No carry operation." << endl;
        } else if (carryCount == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << carryCount << " carry operations." << endl;
        }
    }
    return 0;
}










































