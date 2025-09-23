#include <iostream>

using namespace std;

int main() {

    int n;

    
    while (cin >> n && n != 0)
    {
        int die[6] = {1, 6, 2, 5, 3, 4};
        

        for (int i = 0; i < n; i++)
        {
            string cmd;
            cin >> cmd;
            int tmp;
            if (cmd == "north")
            {
                tmp = die[0];
                die[0] = die[3];
                die[3] = die[1];
                die[1] = die[2];
                die[2] = tmp;
            }
            if (cmd == "south")
            {
                tmp = die[0];
                die[0] = die[2];
                die[2] = die[1];
                die[1] = die[3];
                die[3] = tmp;
            }
            if (cmd == "east")
            {
                tmp = die[0];
                die[0] = die[4];
                die[4] = die[1];
                die[1] = die[5];
                die[5] = tmp;
            }
            if (cmd == "west")
            {
                tmp = die[0];
                die[0] = die[5];
                die[5] = die[1];
                die[1] = die[4];
                die[4] = tmp;
            }
            
        }

        cout << die[0] << "\n";
        
    }
    

    return 0;
}