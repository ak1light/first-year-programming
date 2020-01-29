#include <iostream>
#include <cmath>

        int main(){
                using namespace std;
                long long int n, S = 0, i;

                cin >> n;
                if ( 0 <= n && n <= 1000000000000000){
                    for(i = 0; i <= n; ++i){
                        if (pow(2,i) <= n) ++S;
                        else break;
                    }
                    cout<< S;
                }
                else cout << "oshibka zna4eni9";


        return(0);
}
