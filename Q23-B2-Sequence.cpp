#include <iostream>
#include <set>
using namespace std;


int main()
{
    int n, c = 1;
    set<int> s;
    while (cin >> n)
    {
        int a[n];
        s.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
                break;
            else if (a[i + 1] <= a[i] && i >= 0)
                break;
            for (int j = i; j < n; j++)
            {
                s.insert(a[i] + a[j]);
            }
        }
        if (s.size() == (1 + n) * n / 2)
            cout << "Case #" << c << ": It is a B2-Sequence." << endl
                 << endl;
        else
            cout << "Case #" << c << ": It is not a B2-Sequence." << endl
                 << endl;

        c++;
    }

    return 0;
}