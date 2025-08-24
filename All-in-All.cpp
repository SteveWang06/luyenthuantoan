#include <iostream>
using namespace std;
 
int main() {
    string s1, s2;
    while (cin >> s1 >> s2){
        int p1 = 0, p2 = 0;
        while (p1 < s1.size() && p2 < s2.size()){
            if (s1[p1] == s2[p2]){
                p1++;
                p2++;
            } else {
                p2++;
            }
        }
        if (p1 == s1.size()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}