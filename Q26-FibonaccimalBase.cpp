#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> generateFib(int limit) {

    vector<int> fib = {1, 2};
    while (true)
    {
        int next = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (next > limit)
        {
            break;
        }

        fib.push_back(next);
    }

    return fib;
}



string converToFibBase(int number, const vector<int>& fib) {

    string result;
    bool start = false;
    int remaining = number;

    for (int i = fib.size() - 1; i >= 0; i--)
    {
        if (fib[i] <= remaining)
        {
            result += '1';
            remaining -= fib[i];
            start = true;
        }
        else if (start)
        {

            result += '0';
        }
        
    }

    return result;
}


int main() {

    int n;
    

    cin >> n;

    vector<int> number(n);

    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }

    vector<int> fib = generateFib(100000000);

    for (int i = 0; i < n; i++)
    {
        string fibBase = converToFibBase(number[i], fib);
        cout << number[i] << " = " << fibBase << " (fib)" << endl;
    }
    

    return 0;
}