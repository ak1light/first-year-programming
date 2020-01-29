#include <iostream>
        int main(){
            float a, b;
            char symb;
            using namespace std;
            cin >> a;
            cin >> symb;
            switch(symb){
                case '+':
                    cin >> b;
                    cout << a + b;
                    break;
                case '-':
                    cin >> b;
                    cout << a - b;
                    break;
                case '*':
                    cin >> b;
                    cout << a * b;
                    break;
                case '/':
                    cin >> b;
                    if (b == 0) cout << "oshibka : delenie na 0";
                    else cout << a / b;
                    break;
                default:
                    cout << "net takogo znaka";
                    break;


            }

        return(0);
}
