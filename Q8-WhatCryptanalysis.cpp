

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>

using namespace std;



bool comparePairs(const pair<char, int> &a, const pair<char, int> &b) {
    if (a.second != b.second)
    {
        return a.second > b.second;
    }else
    {
        return a.first < b.first;
    }
    
    
}

int main() {

    int numsLine;
    cin >> numsLine;
    cin.ignore();

    map<char, int> letterCount;

    for (size_t i = 0; i < numsLine; i++)
    {
        string line;
        getline(cin, line);

        for (char c : line)
        {
            if (isalpha(c))
            {
                letterCount[toupper(c)]++;
            }
            
        }
        
    }

    vector<pair<char, int>> letterList(letterCount.begin(), letterCount.end());

    sort(letterList.begin(), letterList.end(), comparePairs);

    for (const auto &entry : letterList)
    {
        cout << entry.first << " " << entry.second << "\n";
    }
    

    return 0;
}





