#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main() {

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int N, I;
        double p;

        cin >> N >> p >> I;

        if (p == 0.0)
        {
            cout << fixed << setprecision(0) << 0.0000 << endl;
        }

        double q = 1 - p;

        // Tử số: xác suất người thứ I thắng ở lần chơi đầu tiên của họ
        double numerator = p * pow(q, I - 1);

        // Mẫu số: tổng xác suất người đó thắng ở mọi vòng (theo cấp số nhân)
        double denominator = 1 - pow(q, N);

        double result = numerator / denominator;

        cout << fixed << setprecision(4) << result << endl;
    }
    
    return 0;
}