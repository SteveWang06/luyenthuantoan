// Bangla numbers normally use ’kuti’ (10000000), ’lakh’ (100000), ’hajar’ (1000), ’shata’ (100) while
// expanding and converting to text. You are going to write a program to convert a given number to text
// with them.
// Input
// The input file may contain several test cases. Each case will contain a non-negative number ≤
// 999999999999999.
// Output
// For each case of input, you have to output a line starting with the case number with four digits
// adjustment followed by the converted text.
// Sample Input
// 23764
// 45897458973958
// Sample Output
// 1. 23 hajar 7 shata 64
// 2. 45 lakh 89 hajar 7 shata 45 kuti 89 lakh 73 hajar 9 shata 58


// Các chữ số Bangla thường dùng 'kuti' (10.000.000), 'lakh' (100.000), 'hajar' (1.000), 'shata' (100) khi mở rộng và chuyển sang dạng chữ.
// Bạn sẽ viết một chương trình để chuyển một số đã cho sang dạng chữ sử dụng các đơn vị trên.

// Dữ liệu vào
// Tệp dữ liệu đầu vào có thể chứa nhiều bộ test. Mỗi bộ test sẽ chứa một số không âm ≤ 999999999999999.

// Dữ liệu ra
// Với mỗi bộ test đầu vào, bạn cần xuất ra một dòng bắt đầu với số thứ tự của test case (dùng đủ 4 chữ số, ví dụ 0001) sau đó là phần văn bản đã được chuyển đổi.

#include <iostream>
using namespace std;


void split(long long n) {
    if (n >= 10000000)
    {
        split(n/10000000);
        cout << " kuti";
        
        n %= 10000000;
    }
    if (n >= 100000)
    {
        split(n/100000);
        cout << " lakh";
        
        n %= 100000;
    }
    if (n >= 1000)
    {
        split(n/1000);
        cout << " hajar";
        
        n %= 1000;
    }
    if (n >= 100)
    {
        split(n/100);
        cout << " shata";
        
        n %= 100;
    }
    if (n)
    {
        cout << " " << n;
        
    }
    

}

int main() {

    long long n;
    int caseNo = 1;

    while (cin >> n)
    {
        cout.width(4);
        cout << caseNo++ << ".";

        if (n == 0)
        {
            cout << " 0";
        }else {
            split(n);
        }
        cout << endl;

    }
    
    return 0;
}