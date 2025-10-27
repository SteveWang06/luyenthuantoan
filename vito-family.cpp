#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int testCase, relation;

    cin >> testCase;

    while (testCase--)
    {
        cin >> relation;
        vector<int> address(relation);

        for (int i = 0; i < relation; i++)
        {
            cin >> address[i];
        }

        sort(address.begin(), address.end());

        int sum = 0;

        int median = address[relation/2];

        for (int i = 0; i < relation; i++)
        {
            sum += abs(address[i] - median);
        }
        
        cout << sum << "\n";
    }
    

    return 0;
}