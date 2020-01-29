#include <iostream>
#include <cmath>
        int main(){
        using namespace std;
        float a, b, c, D, t;
        cin >> a;
        cin >> b;
        cin >> c;
            if( a != 0 && b != 0 && c != 0){
               D = b*b - 4*a*c;
               if(D > 0) {
                    cout << "x1 = " << (-b + sqrt(D)) / (2*a) << "\n"<< "x2 = " << (-b - sqrt(D)) / (2*a);
               }
               else if(D == 0){
                    cout << "x = " << (-b + sqrt(D)) / (2*a);
                    }
               else cout << "D < 0";
            }
            else if( a == 0 && b != 0 && c != 0){
                    cout << "x = " << -c / b;
                }
            else if( a != 0 && b == 0 && c != 0){
                        t = -c / a;
                        if (t >= 0){
                            cout << "x = +- " << sqrt(t);
                        }
                        else cout << "oshibka : popitka izvle4eni9 korn9 iz otricatelnogo 4isla";
                }
            else if( a != 0 && b != 0 && c == 0){
                    cout << "x = " << -b / a;
                }
            else if( a == 0 && b == 0 && c != 0){
                    cout << "korney net";
                }
            else if( a == 0 && b != 0 && c == 0){
                    cout << "x = 0";
                }
            else if( a != 0 && b == 0 && c ==0){
                    cout << "x = 0";
                }
            else if( a == 0 && b == 0 && c == 0){
                    cout << "luboe zna4enie";
                }
        return(0);
}
