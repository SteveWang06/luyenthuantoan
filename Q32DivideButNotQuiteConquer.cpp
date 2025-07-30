#include <iostream>
using namespace std;

int main()
{

    int n, m;

    while (cin >> n >> m)
    {
        if (n < 2 || m < 2)
        {
            cout << "Boring!" << endl;
            continue;
        }

        int a[40], cnt = 0;

        a[cnt++] = n;
        while (n != 1)
        {
            if (n % m != 0)
            {
                break;
            }
            a[cnt++] = n / m;
            n = n / m;
        }

        if (n==1)
        {
            for (int i = 0; i < cnt - 1; i++)
            {
                cout << a[i] << " ";
            }
            cout << "1" << endl;
            
        }else
        {
            cout << "Boring!" << endl;
        }
        
        
    }

    return 0;
}