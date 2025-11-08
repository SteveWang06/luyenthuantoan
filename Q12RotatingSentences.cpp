#include <iostream>
using namespace std;

int main() {
    string sentence[105];
    int col = 0;
    int row = 0;

    while (getline(cin, sentence[col])) {
        col++;
        row = max(row, (int)sentence[col - 1].length());
    }

    for (int i = 0; i < row; i++) {
        for (int j = col - 1; j >= 0; j--) {
            if (i < sentence[j].length()) {
                cout << sentence[j][i];
            }
        }
        cout << endl;
    }

    return 0;
}