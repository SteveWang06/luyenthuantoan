#include <iostream>
using namespace std;


int mygcd(int n1, int n2) {

    while ((n1 %= n2) && (n2 %= n1));
    return n1 + n2;
    
}

int main() {


    int t;
    string s1, s2;
    cin >> t;
    
    for (int Case = 1; Case <= t; Case++)
    {
        cin >> s1 >> s2;
        int n1 = 0, n2 = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            n1 *= 2;
            n1 += s1[i] - '0';
        }

        for (int i = 0; i < s2.size(); i++)
        {
            n2 *= 2;
            n2 += s2[i] - '0';
        }

        cout << "Pair #" << Case;
        if (mygcd(n1, n2) > 1)
        {
            cout << ": All you need is love!\n";
        }else
        {
            cout << ": Love is not all you need!\n";
        }
        
        
        
    }
    

    return 0;
}