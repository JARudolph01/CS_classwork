#include <iostream>
#include "math.h"
using namespace std;

int main()
{
    double a=5;
    double x = sqrt(a)/6;
    double y = 2*sqrt(a)/3;
    double z = 2*sqrt(a)/3;
    double maxVolume = x*y*z;

    cout << maxVolume <<"\n";
    
    /*
    x = sqrt(A)/6 units
    y = 2*sqrt(A)/3 units
    z = 2*sqrt(A)/3 units.
    Hence, the maximum volume is 2*A^(3/2)/27 cubic units.
    */

   return 0;
}