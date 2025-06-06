#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


int main() {

    int testCase;
    cin >> testCase;
    cin.ignore();
    while (testCase--)
    {
        string header;
        getline(cin, header);

        int n = stoi(header.substr(header.find('=') + 1));

        vector<vector<long long>> matrix(n, vector<long long>(n));

        for (int i = 0; i < n; i++)
        {
            string line;
            getline(cin, line);
            stringstream ss(line);
            for (int j = 0; j < n; j++)
            {
                ss >> matrix[i][j];
            }
            
        }

        bool symmetric = true;

        for (int i = 0; i < n && symmetric; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] < 0 || matrix[i][j] != matrix[n - 1 - i][n - 1 - j])
                {
                    symmetric = false;
                }
                
            }
            
        }

        cout << "Test #" << testCase << ": ";

        cout << (symmetric ? "Symmetric." : "Non-symmetric.") << endl;
    }
    

    return 0;
}