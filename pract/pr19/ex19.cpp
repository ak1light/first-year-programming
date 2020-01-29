#include <iostream>
#define T 10
#define T1 100000
        int main(){
            using namespace std;
            int n;
            cin >> n;
            int i, a[T], b;
            for(i = 0; i < T; ++i) a[i] = 0;
            for(i = 0; i < n; ++i) {
                    cin >> b;
                    ++a[b];
            }
            for(i = 0; i < T; ++i){
                if(a[i] > 0) {
                    cout << i << ": " << a[i] << "\n";
                }
            }




        return(0);
}
