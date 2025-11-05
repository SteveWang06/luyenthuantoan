
#include <iostream>
#include <string>
using namespace std;

int main() {
    string encodedMessage;
    string keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"; 
    getline(cin, encodedMessage); 

    string decodedMessage = "";

    for (char c : encodedMessage) {
        if (c == ' ') {
            decodedMessage += ' '; 
        } else {
            size_t pos = keyboard.find(tolower(c));
            if (pos != string::npos && pos >= 2) {
                decodedMessage += keyboard[pos - 2];
            }
        }
    }

    cout << decodedMessage << endl; 
    return 0;
}



