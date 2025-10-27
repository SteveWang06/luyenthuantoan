
#include <iostream>
#include <string>

using namespace std;

bool isMultipleOf11(const string& number) {
    int sum = 0;


    for (size_t i = 0; i < number.length(); ++i) {
        int digit = number[i] - '0';
        if (i % 2 == 0)
            sum += digit;
        else
            sum -= digit;
    }

    return (sum % 11 == 0);
}

int main() {
    string number;
    while (cin >> number && number != "0") {
        if (isMultipleOf11(number))
            cout << number << " is a multiple of 11." << endl;
        else
            cout << number << " is not a multiple of 11." << endl;
    }

    return 0;
}
