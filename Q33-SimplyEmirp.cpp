

#include <iostream>
#include <cmath>


using namespace std;


bool isPrime(int n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(int i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0) return false;
    }

    return true;
}


int reverseNumber(int n) {

    int rev = 0;

    while(n > 0) {

        rev = rev * 10 + n % 10;
        n /= 10;

    }


    return rev;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    while(cin >> n) {

        // nếu không phải là số nguyên tố thì in ra "is not prime"
        if(!isPrime(n)) {
            cout << n << " is not prime.\n";
        } else {
            int rev = reverseNumber(n);

            // nếu là số nguyên tố nhưng sau khi đảo ngược, lại là số nguyên tố khác (khác số ban đầu) thì in ra "is emirp"
            if(rev != n && isPrime(rev)) {
                cout << n << " is emirp.\n";
            } else {

                // nếu là số nguyên tố nhưng sau khi đảo ngược số mới không phải số nguyên tố thì in ra "is prime"
                cout << n << " is prime.\n";
            }
        }
    }

}

