#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;
    int field = 1;

    while (cin >> n >> m && (n || m))
    {
        vector<string> grid(n);
        for (int i = 0; i < n; i++)
        {
            cin >> grid[i];
        }
        
        vector<string> result = grid;
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '*')
                {
                    continue;
                }

                int count = 0;

                for (int d = 0; d < 8; d++)
                {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '*')
                    {
                        count++;
                    }
                    
                }
                result[i][j] = char('0' + count);
                
                
            }
            
        }
        cout << "Field #" << field << ":\n";
        for (auto &row : result)
        {
            cout << row << "\n";
        }
        cout << "\n";
        
    }

    return 0;
    
}