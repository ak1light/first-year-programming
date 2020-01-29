#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a, b ,x1, x2, d, z, xmax, xmin, x;
    bool firstmaxmin = true;
    cout << "vvedite a, b, x1, x2, d: ";
    cin >> a >> b >> x1 >> x2 >> d;  //    0.7 1.2 0.5 1.5 0.05
    cout << "|  " << 'x' << " | " << 'z' << " |" <<  endl << "|-----|-----|" << endl;
    xmax = 0;
    xmin = 0;
    for(float x = x1; x <= x2; x += d){

        if (x <= a) z = log(x) + sin(x);
        else if ((a < x)&& (x < b)) z = log(x) + cos(x);
        else if( x >= b) z = tan(x);
        if (firstmaxmin) {
            xmax = z;
            xmin = z;
            firstmaxmin = false;
        }
        else if (z > xmax) xmax = z;
        else if (z < xmin) xmin = z;
        cout <<  "|  " << x << " | " << z<< " |" <<  endl;
    }

    cout << endl << "max: " << xmax << "  min: " << xmin << endl;
    return 0;
}
