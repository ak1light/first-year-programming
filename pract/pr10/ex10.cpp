#include <iostream>

        int main(){
                using namespace std;
                int i, n;
                float a, S = 1, sn = 1;
                cin >> a;
                cin >> n;

                if (n >= 0){
                    for (i = 0; i < n; ++ i) S *= a;
                    cout << S;
                    }

                else if (n < 0 && a != 0){
                    for (i = 0; i < n * -1; ++i){
                            sn *= a;
                            if( i == (n * -1) - 1) S = 1 / sn;
                    }
                    cout << S;
                }
                else if (n < 0 && a == 0) cout <<"oshibka: popitka deleni9 na 0 ";


        return(0);
}
