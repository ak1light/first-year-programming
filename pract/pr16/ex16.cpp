#include <iostream>
#define T 100

        void factorization(int n);

        int main(){

            int n;
            std::cin >> n;
            factorization(n);
            return(0);

        }
            void factorization(int n ){
                int i = 2, counter = 0;

                while( n > 0){
                    if( n % i == 0){
                        n = n / i;
                        ++counter;
                    }
                    else {

                        if (n == 1 && counter == 1 ){
                                std::cout << i ;
                                break;

                        }
                        else if (n == 1 && counter > 1){
                            std:: cout << i << "^" << counter;
                            break;

                        }
                        else if(n > 1 && counter == 1){
                            std::cout << i << "*";

                        }
                        else if(n > 1 && counter > 1){
                            std::cout << i << "^" << counter << "*";

                        }
                        ++i;
                        counter = 0;
                    }
                }

            }


