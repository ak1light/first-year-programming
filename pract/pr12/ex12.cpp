#include <iostream>
        int main(){
                int a,i, S = 0;
                using namespace std;
                cin >> a;
                if ( a > 0){
                    for (i = a-1; i > 1; --i){
                        if(a % i == 0) break;
                    }
                }
                else cout << "oshibka 4islo <= 0";
                if (i == 1) cout << "Prostoe";
                else cout << "Sostavnoe";
        return(0);
}
