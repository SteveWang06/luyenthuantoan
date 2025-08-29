#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define PI acos(0.0)* 2.0

int main() {
    double a; // là gốc giữa 2 vệ tinh và trái đất 
    double s; // là độ cao của vệ tinh 
    double chord, arc;
    string unit;
    double earth_r = 6440.0; // bán kính trái đất
    

    while (cin >> s >> a >> unit)
    {
        double r = earth_r + s; // bán kính quỹ đạo 
        if (unit == "min")
        {
            a /= 60.0;
        }
        if (a > 180.0)
        {
            a = 360.0 - a;
        }
        
        chord = 2.0 * r * sin((a / 2) * (PI / 180.0));
        arc = 2.0 * PI * r * a / 360.0;

        cout << fixed << setprecision(6) << arc << " " << chord << endl;
    }
    
}

