#include <iostream>
#include <string>

using namespace std;



int charToNum(char c) {

    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }

    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 10;
    }

    if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 36;
    }

    return -1;
}




int main() {

    string number;

    while (cin >> number)
    {
        int maxDigit = -1;
        int digitNum;


        for (char c : number)
        {
            int val = charToNum(c);
            if (val > maxDigit)
            {
                maxDigit = val;
            }
            
        }

        bool found = false;

        for (int base = maxDigit + 1; base < 62; base++)
        {
            digitNum = 0;
            for (char c : number)
            {
                digitNum += charToNum(c);
            }
            
            if (digitNum % (base - 1) == 0)
            {
                cout << base << endl;
                found = true;
                break;
            }
            
        }

        if (!found)
        {
            cout << "such number is impossible!" << endl;
        }
        
        
    }
    

    return 0;
}







