#include <iostream>
#include <cmath>

using namespace std;

const double epsilon = 1e-10;
bool ravenstvo(double a, double b) {
    return (abs(a - b) < epsilon);
}
int main(){
    double a, b ,x1, x2, d, z, xmax, xmin;
    bool firstmaxmin = true;
    cout << "vvedite a, b, x1, x2, d: ";
    cin >> a >> b >> x1 >> x2 >> d;  //    0.7 1.2 0.5 1.5 0.05
    cout << "|  " << 'x' << " | " << 'z' << " |" <<  endl << "|-----|-----|" << endl;
    xmax = 0;
    xmin = 0;

    for (double x = x1; x < x2 || ravenstvo(x, x2); x += d) {

        if (x < a || ravenstvo(x, a)) z = log(x) + sin(x);// x <= a
        else if (x < b) z = log(x) + cos(x); // a < x < b
        else z = tan(x); // x >= b
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
