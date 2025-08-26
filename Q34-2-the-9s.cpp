#include <iostream>

using namespace std;


int func(string s, int count) {

    int total = 0;

    for (char c : s) {
        total += c - '0';
    }

    count++;

    if (total == 9)
    {
        return count;
    }else if (total < 9)
    {
        return 0;
    }else {
        return func(to_string(total), count);
    }
}

int main() {
    string s;
    int ans;

    while(cin >> s) {
        if (s == "0")
        {
            break;
        }
        ans = func(s, 0);

        if (ans == 0)
        {
            cout << s << " is not a multiple of 9." << endl;
        }else {
            cout << s << " is a multiple of 9 and has 9-degree " << ans << "." << endl;

        }
        
        
    }
}