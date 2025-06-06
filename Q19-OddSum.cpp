#include <iostream>

using namespace std;

int main() {

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int a, b, sum = 0;

        cin >> a;

        cin >> b;

        for (int i = a; i <= b; i++)
        {
            if (i % 2 != 0)
            {
                sum += i;
            }
            
        }

        cout << "case " << testCase << ": " << sum << endl;

        
    }
    
    return 0;
}