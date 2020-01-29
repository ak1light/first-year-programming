#include <iostream>
        int main(){
                long long int s, l1, r1, l2, r2;
                bool f_is = false;
                using namespace std;
                cin >> s >> l1 >> r1 >> l2 >> r2;

                    for(int i = l1; i <= r1; ++i){
                        for(int j = l2; j <= r2; ++j)
                                if(s == i + j) {
                                    cout << i << " " << j;
                                    f_is = true; // когда число найдено, выходим из внутреннего цикла
                                    break; // дальнейшее выполнение бессмысленно
                                }
                        if (f_is) break; // выходим из внешнего цикла
                    }
                    if (!f_is) cout << "-1";

                return(0);
}


