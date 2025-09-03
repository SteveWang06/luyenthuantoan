#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    
    double x1, y1, x2, y2, x3, y3, x4, y4;

    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
    {
        double cx, cy;
        double a1, b1, a2, b2;

        if (x1 == x3 && y1 == y3)
        {
            cx = x1; cy = y1;
            a1 = x2; b1 = y2;
            a2 = x4; b2 = y4;
        } else if (x1 == x4 && y1 == y4)
        {
            cx = x1; cy = y1;
            a1 = x2; b1 = y2;
            a2 = x3; b2 = y3;
        } else if (x2 == x3 && y2 == y3)
        {
            cx = x2; cy = y2;
            a1 = x1; b1 = y1;
            a2 = x4; b2 = y4;
        } else if (x2 == x4 && y2 == y4)
        {
            cx = x2; cy = y2;
            a1 = x1; b1 = y1;
            a2 = x3; b2 = y3;
        }
        
        double x = a1 + a2 - cx;
        double y = b1 + b2 - cy;

        cout << fixed << setprecision(3) << x << " " << y << endl;
        
    }
    return 0;
    
    
}