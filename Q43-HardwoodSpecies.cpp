#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n;
    getline(cin, s);
    getline(cin, s);

    while (n--)
    {
        map<string, int> mp;
        int sum = 0;

        while (getline(cin, s) && s != "")
        {
            mp[s]++;
            sum++;
        }

        for (auto i:mp)
        {
            cout << i.first << " " << fixed << setprecision(4) << (double) i.second / sum * 100 << "\n";
        }
        cout << "\n";
        
    }

    return 0;
    
}