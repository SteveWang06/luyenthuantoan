#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string str;

    bool flag = false;

    while (getline(cin, str))
    {
        if (flag)
        {
            cout << "\n";
        }

        flag = true;

        vector<int> count(128, 0);

        for (char c : str)
        {
            count[(int) c]++;
        }
        int len = str.size();

        for (int i = 1; i <= len; i++)
        {
            for (int j = 127; j >= 32; j--)
            {
                if (count[j] == i)
                {
                    cout << j << " " << i << "\n";
                }
                
            }
            
        }
        
        
    }

    return 0;
    
}