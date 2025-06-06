// Your job is, given a positive number N, determine if it is a multiple of eleven.
// Input
// The input is a file such that each line contains a positive number. A line containing the number ‘0’ is
// the end of the input. The given numbers can contain up to 1000 digits.
// Output
// The output of the program shall indicate, for each input number, if it is a multiple of eleven or not.
// Sample Input
// 112233
// 30800
// 2937
// 323455693
// 5038297
// 112234
// 0
// Sample Output
// 112233 is a multiple of 11.
// 30800 is a multiple of 11.
// 2937 is a multiple of 11.
// 323455693 is a multiple of 11.
// 5038297 is a multiple of 11.
// 112234 is not a multiple of 11.


// Nhiệm vụ của bạn là, với một số nguyên dương N được cho, xác định xem nó có phải là bội của 11 hay không.

// Dữ liệu đầu vào
// Dữ liệu đầu vào là một tập tin trong đó mỗi dòng chứa một số nguyên dương. Một dòng chứa số ‘0’ sẽ đánh dấu kết thúc dữ liệu đầu vào. Các số được đưa vào có thể dài tới 1000 chữ số.

// Dữ liệu đầu ra
// Chương trình phải thông báo, đối với mỗi số đầu vào, liệu nó có phải là bội của 11 hay không.

// Ví dụ đầu vào
// 112233  
// 30800  
// 2937  
// 323455693  
// 5038297  
// 112234  
// 0  


// Ví dụ đầu ra
// 112233 là bội của 11.  
// 30800 là bội của 11.  
// 2937 là bội của 11.  
// 323455693 là bội của 11.  
// 5038297 là bội của 11.  
// 112234 không phải là bội của 11.  

#include <iostream>
#include <string>

using namespace std;

// Hàm kiểm tra một số lớn có phải là bội của 11 không
bool isMultipleOf11(const string& number) {
    int sum = 0;

    // Áp dụng quy tắc chia hết cho 11:
    // Lấy hiệu giữa tổng các chữ số ở vị trí chẵn và tổng các chữ số ở vị trí lẻ
    for (size_t i = 0; i < number.length(); ++i) {
        int digit = number[i] - '0';
        if (i % 2 == 0)
            sum += digit;
        else
            sum -= digit;
    }

    return (sum % 11 == 0);
}

int main() {
    string number;
    while (cin >> number && number != "0") {
        if (isMultipleOf11(number))
            cout << number << " is a multiple of 11." << endl;
        else
            cout << number << " is not a multiple of 11." << endl;
    }

    return 0;
}
