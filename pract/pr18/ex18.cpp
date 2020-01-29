#include <iostream>
#include <stdlib.h>
#include <time.h>
#define T 20
        int main(){
        srand((signed)time(0));
        using namespace std;
        int a[T];
        for(int i = 0; i < T; ++i) {
            a[i] = rand()%201 - 100;
        }
        int min1 = a[0], max1 = a[0];
        for(int i = 0; i < T; ++ i){
            if (a[i] < min1) min1 = a[i];
            if (a[i] > max1) max1 = a[i];
        }
        for(int i = 0; i < T; ++i){
            cout << a[i] << " ";
        }

        cout << "\n" << min1 << "\n" << max1;


        return(0);
}
