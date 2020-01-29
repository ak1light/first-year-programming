#include <iostream>
#include <time.h>
#include <stdlib.h>
        int main(){
                using namespace std;
                int i = 1, sovp;

                while (i == 1){
                    srand(time(0));
                    int n = rand()%101;
                    int j = 0;
                    cout<< "{Vas privetstvyet igra}\n";
                    while(j < 5){
                        cin >> sovp;
                        if(sovp == n) {
                                cout<<"Pozdravlyau! Vi ygadali\n";
                                j = 7;
                        }
                        else if(sovp < n) cout << "Zagadannoe 4islo bolshe\n";
                        else if(sovp > n) cout << "Zagadannoe 4islo menshe\n";
                         ++j;
                    }
                    if (j == 5) cout << "Vi proigrali. Bilo zagadano: {"<< n << "}\n";
                    ++i;
                    cout << "Xotite na4at sna4ala?(1 - Da)\n";
                    cin >> i;
                    system("CLS");
                }


        return(0);
}
