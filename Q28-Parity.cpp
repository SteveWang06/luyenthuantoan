#include <iostream>
#include <string>

using namespace std;


int main() {

    int i;
    

    while(cin >> i && i != 0) {

        string binary = "";
        int count = 0;
        int temp = i;

        while(temp > 0) {

            int bit = temp % 2;
            binary = char('0' + bit) + binary;
            if(bit == 1) count++;
            temp/=2;

        }


        

        cout << "The parity of " << binary << " is " << count << " (mod 2)." << endl;

    }

    return 0;
}