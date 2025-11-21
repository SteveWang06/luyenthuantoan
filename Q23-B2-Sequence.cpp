#include <iostream>
using namespace std;
#define maxn 20005
 
int main() {
    int n, Case = 1;
    while (cin >> n) {
        int b[n], sum[maxn];
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < maxn; i++) {
            sum[i] = 0;
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int x = b[i] + b[j];
                if (sum[x]) {
                    flag = false;
                    break;
                } else {
                    sum[x] = 1;
                }
            }
            if (!flag) break;
        }
        if (flag) cout << "Case #" << Case++ << ": It is a B2-Sequence.\n\n";
        else cout << "Case #" << Case++ << ": It is not a B2-Sequence.\n\n";
    }
    return 0;
}