#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, s, d;
    cin >> T;
    while (T--){
        cin >> s >> d;
        if ((s + d) % 2 || s < d) cout << "impossible\n";
        else {
            cout << (s+d)/2 << " " << (s-d)/2 << "\n";
        }
    }
    return 0;
}