// The world-known gangster Vito Deadstone is moving to New York. He has a very big family there, all
// of them living in Lamafia Avenue. Since he will visit all his relatives very often, he is trying to find a
// house close to them.
// Vito wants to minimize the total distance to all of them and has blackmailed you to write a program
// that solves his problem.
// Input
// The input consists of several test cases. The first line contains the number of test cases.
// For each test case you will be given the integer number of relatives r (0 < r < 500) and the street
// numbers (also integers) s1, s2, . . . , si, . . . , sr where they live (0 < si < 30000 ). Note that several
// relatives could live in the same street number.
// Output
// For each test case your program must write the minimal sum of distances from the optimal Vito’s house
// to each one of his relatives. The distance between two street numbers si and sj is dij = |si − sj |.
// Sample Input
// 2
// 2 2 4
// 3 2 4 6
// Sample Output
// 2
// 4

// Gã xã hội đen nổi tiếng Vito Deadstone đang di chuyển đến New York. Anh ta có một gia đình rất lớn ở đó, tất cả họ đều sống trên Đại lộ Lamafia. Vì anh ta sẽ thường xuyên thăm tất cả các người thân của mình, anh ta đang cố gắng tìm một ngôi nhà gần họ.
// Vito muốn giảm thiểu tổng khoảng cách đến tất cả các người thân và đã tống tiền bạn để viết một chương trình giải quyết vấn đề của anh ta.
// Dữ liệu đầu vào
// Dữ liệu đầu vào bao gồm nhiều bộ kiểm tra. Dòng đầu tiên là số lượng bộ kiểm tra.
// Đối với mỗi bộ kiểm tra, bạn sẽ được cung cấp số lượng người thân r (0 < r < 500) và số nhà của họ (cũng là các số nguyên) s1, s2, ..., si, ..., sr, nơi họ sống (0 < si < 30000). Lưu ý rằng một số người thân có thể sống cùng một số nhà.
// Dữ liệu đầu ra
// Đối với mỗi bộ kiểm tra, chương trình của bạn phải in ra tổng khoảng cách tối thiểu từ ngôi nhà tối ưu của Vito đến mỗi người thân của anh ta. Khoảng cách giữa hai số nhà si và sj là dij = |si − sj|.
// Ví dụ đầu vào
// 2
// 2 2 4
// 3 2 4 6
// Ví dụ đầu ra
// 2
// 4

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>  

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int r;
        cin >> r;
        vector<int> v(r);
        for(int i = 0; i < r; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int median = v[r/2];
        int sum = 0;
        for(int i = 0; i < r; i++) {
            sum += abs(v[i] - median);
        }
        cout << sum << endl;
    }
    return 0;
}