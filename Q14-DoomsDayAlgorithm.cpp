#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {


    vector<string> days = {
        "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday", "Sunday"
    };

    // Doomsday của từng tháng trong năm 2011
    int doomsday[12] = {
        10, // Jan (1/10)
        21, // Feb (2/21)
        0,  // placeholder (March)
        4,  // April
        9,  // May
        6,  // June
        11, // July
        8,  // August
        5,  // September
        10, // October
        7,  // November
        12  // December
    };

    int t;
    cin >> t;
    while (t--)
    {
        int m, d;
        cin >> m >> d;
        int offset = d - doomsday[m - 1];
        int indexDay = (offset % 7 + 7) % 7;
        cout << days[indexDay] << endl;
    }
    

    return 0;
}