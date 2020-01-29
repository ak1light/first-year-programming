#include <iostream>
        int main(){
            using namespace std;
            int i, n, S = 1;
            cin >> n;
            if ( n > 0){
                for (i = 1; i <= n; ++i){
                    S *= i;
                }
            cout << S;
            }
            else cout << "nevernoe 4islo n <= 0";



        return(0);
}
