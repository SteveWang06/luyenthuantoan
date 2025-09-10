#include <iostream>
#include <algorithm>

using namespace std;



int main() {

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    swap(a[i], a[j]);
                    count++;
                }
                
            }
            
        }

        cout << "Optimal train swapping takes " << count << " swaps.\n";
        
    }
    

    return 0;
}