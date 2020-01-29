#include <iostream>
#define T 10000
    using namespace std;
    void output(int b[], int n);

    void fnbubble(int a[], int n){
        for(int j = 0; j < n - 1; ++ j){
            for(int i = 0; i < n - 1 - j; ++ i){
                if (a[i] > a[i + 1]) {
                    a[i] = a[i] + a[i + 1];
                    a[i + 1] = a[i] - a[i + 1];
                    a[i] = a[i] - a[i + 1];
                }
            }

        }


    }
    int main(){
        int a[T];
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> a[i];

        fnbubble(a, n);
        output(a, n);

    return(0);
}

    void output(int a[], int size1){

        for(int i = 0; i < size1; ++i){
            cout << a[i] << " ";
        }
    }
