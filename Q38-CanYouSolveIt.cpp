#include <iostream>

using namespace std;


int main() {


    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int x, y, step1, step2, n;

        cout << "Case " << i << ": ";
        cin >> x >> y;

        if (x == 0 && y == 0)
        {
            step1 = 0;
        }else{
            n = x + y - 1;
            step1 = (n * n + 3 * n) / 2 + (x + 1);

        }

        cin >> x >> y;
        n = x + y - 1;
        if (x == 0 && y == 0)
        {
            step2 = 0;
        }else{
            n = x + y - 1;
            step2 = (n * n + 3 * n) / 2 + (x + 1);

        }
        cout << step2 - step1 << endl;
    }
    

    return 0;
}