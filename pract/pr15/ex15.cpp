#include <iostream>
#define T 100000
        int main(){
            using namespace std;
            long int a[T], i, n, j,k, counter,checkit = 1,counter1 = 0;
            cin >> n;

            long int b[n];
            for(i = 1; i <= n; ++i) b[i] = 0;
            for(i = 1; i <= n; ++i) cin >> a[i];

                i = 1;
                while(i <= n){
                    b[i] = a[i];

                    if(i == 1) {
                            cout << b[i];
                            cout << "\n";
                            ++i;
                            continue;
                    }

                    else if(i <= 5){
                        for(counter = 1; counter < i; ++counter){
                            for(j = 1; j <= i - 1; ++j) {
                                    if (b[j] < b[j+1]){
                                            //  swap(b[j], b[j+1]);
                                            b[j] = b[j] + b[j+1];
                                            b[j+1] = b[j] - b[j+1];
                                            b[j] = b[j] - b[j+1];
                                    }
                            }
                        }
                    for(k = 1; k <= i; ++k) cout << b[k] << " ";
                    cout << "\n";
                    }

                    else if(i > 5){
                        for(counter = i; counter == i; ++counter){ // sdvig + zamena
                            if(a[counter] < b[5]){
                                for(counter1 = 1; counter1 <= 4; ++counter1) b[counter1] = b[counter1 + 1];
                                b[5] = a[counter];
                            }
                            else if(a[counter] < b[4] && a[counter] > b[5]){
                                    for(counter1 = 1; counter1 <= 3; ++counter1) b[counter1] = b[counter1 + 1];
                                            b[4] = a[counter];
                            }
                            else if(a[counter] < b[3] && a[counter] > b[4] && a[counter] > b[5]){
                                    for(counter1 = 1; counter1 <= 2; ++counter1) b[counter1] = b[counter1 + 1];
                                            b[3] = a[counter];
                            }
                            else if(a[counter] < b[2] && a[counter] > b[3] && a[counter] > b[4] && a[counter] > b[5]){
                                            b[1] = b[2];
                                            b[2] = a[counter];
                            }
                            else if(a[counter] < b[1] && a[counter] > b[2] && a[counter] > b[3] && a[counter] > b[4] && a[counter] > b[5]){
                                            b[1] = a[counter];
                            }
                        }
                        for(k = 1; k <= 5; ++k) cout << b[k] << " ";
                        cout << "\n";
                    }
                ++i;
                }

        return(0);
}
