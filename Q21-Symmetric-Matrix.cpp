#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    char ch;
    cin >> T;

    for (int Case = 1; Case <= T; Case++)
    {
        cin >> ch >> ch >> n;
        long long a[n][n];
        bool isSymmetric = true;

        // Nhập ma trận
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];

                // Kiểm tra phần tử không âm
                if (a[i][j] < 0)
                    isSymmetric = false;
            }
        }

        // Kiểm tra tính đối xứng
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] != a[n - 1 - i][n - 1 - j])
                {
                    isSymmetric = false;
                    break;
                }
            }
            if (!isSymmetric)
                break;
        }

        // In kết quả
        cout << "Test #" << Case << ": ";
        if (isSymmetric)
            cout << "Symmetric.\n";
        else
            cout << "Non-symmetric.\n";
    }

    return 0;
}