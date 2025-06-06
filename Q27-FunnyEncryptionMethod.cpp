#include <iostream>
#include <string>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;

    while (testCase--) {
        int M;
        cin >> M;

        // b1: số bit 1 trong nhị phân của M (thập phân)
        int b1 = __builtin_popcount(M);

        // b2: số bit 1 trong nhị phân của M khi xem là HEX
        string M_str = to_string(M);
        int hexValue = 0;

        for (char c : M_str) {
            hexValue = hexValue * 16 + (c - '0');
        }

        int b2 = __builtin_popcount(hexValue);

        cout << b1 << " " << b2 << endl;
    }

    return 0;
}
