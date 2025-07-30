#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    int t, n, p, h;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        int a[n + 1];
        memset(a, 0, sizeof(a));

        for (int i = 0; i < p; i++)
        {
            cin >> h;
            for (int j = h; j <= n; j += h)
            {
                a[j] = 1;
            }
        }

        for (int i = 6; i <= n; i+=7)
        {
            a[i] = 0;
        }

        for (int i = 7; i <= n; i+=7)
        {
            a[i] = 0;
        }

        int sum = 0;

        for (int i = 1; i <= n; i++)
        {
            sum += a[i];
        }
        
        cout << sum << "\n";
        
    }

    return 0;
}