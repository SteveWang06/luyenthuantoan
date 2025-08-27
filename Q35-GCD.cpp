#include <iostream>
#include <algorithm>
using namespace std;




int gcd(int x, int y) {
    while ((x %= y) && (y %= x));
    return x + y;
}


int main() {


    int n;

    while(cin >> n && n) {
        int g = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                g += gcd(i, j);
            }
            
        }
        cout << g << "\n";
        
    }


    return 0;
}