#include <iostream>
#include  <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {

    vector<string> lines;
    string line;
    int maxLength = 0;

    while (getline(cin, line))
    {
        lines.push_back(line);
        maxLength = max(maxLength, (int)line.length());
    }

    for (int col = 0; col < maxLength; col++)
    {
        for (int row = lines.size() - 1; row >= 0; --row)
        {
            if (col < lines[row].length())
            {
                cout << lines[row][col];
            }else
            {
                cout << " ";
            }
            
            
        }
        cout << "\n";
    }
    

    return 0;
}