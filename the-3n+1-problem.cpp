
#include <iostream>
using namespace std;

// Tính độ dài chu trình của một số n
int cycle_length(int n) {
    int count = 1;
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        count++;
    }
    return count;
}

int main() {
    int i, j;
    while (cin >> i >> j) {
        int start = min(i, j);
        int end = max(i, j);
        int max_cycle = 0;

        for (int k = start; k <= end; ++k) {
            int len = cycle_length(k);
            if (len > max_cycle)
                max_cycle = len;
        }

        cout << i << " " << j << " " << max_cycle << endl;
    }

    return 0;
}

