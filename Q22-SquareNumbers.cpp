#include <iostream>
#include <cmath>

using namespace std;


int main() {

    int a, b, count;

    while (cin >> a >> b)
    {
        if (a == 0 || b == 0)
        {
            break;
        }
        
        int lower = ceil(sqrt(a));      //số nguyên nhỏ nhất có bình phương ≥ a.
        int upper = floor(sqrt(b));    //số nguyên lớn nhất có bình phương ≤ b.
        int count = upper - lower + 1;

        cout << count << endl;
    }
    


    return 0;
}