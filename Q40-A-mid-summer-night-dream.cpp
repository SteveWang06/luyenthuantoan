#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;

    while (cin >> n)
    {
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);

        int min1 = a[(n - 1) / 2];
        int min2 = a[n / 2];
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == min1 || a[i] == min2)
            {
                ans++;
            }
            
        }
        
        

        cout << min1 << " " << ans << " " << min2 - min1 + 1 << endl;
        
    }
    
}