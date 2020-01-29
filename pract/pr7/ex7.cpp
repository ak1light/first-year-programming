#include <iostream>
#include <cmath>
        int main(){
            int sw;
            float a, b, c, Ax, Ay, Bx, By, Cx, Cy, p, S, det;
            using namespace std;
            cout << "1 - storoni 2 - koordinati\n";
            cin >> sw;
            switch(sw){
                case 1:
                    cin >> a;
                    cin >> b;
                    cin >> c;
                    if (a + b > c && a + c > b && b + c > a){
                       p = (a + b + c) / 2;
                       S = p*(p - a)*(p - b)*(p - c);
                       if(S >= 0) cout<< "S = " << sqrt(p*(p - a)*(p - b)*(p - c));
                       else cout << "oshibka: izvle4enie korn9 is otric 4isla";
                    }
                    else cout<< "nepravilnie dlini storon";
                    break;
                case 2:
                    cin >> Ax >> Ay;
                    cin >> Bx >> By;
                    cin >> Cx >> Cy;
                    det = (Ax - Cx) * (By - Cy) - (Ay - Cy) * (Bx - Cx);
                    if (det < 0) cout << "S = " << det * -0.5;
                    else if (det > 0) cout << "S = " << det * 0.5;
                    else if (det == 0) cout << "S = 0";
                    break;

                default:
                    cout << "ne to zna4enie";
                    break;

            }

        return(0);
}
