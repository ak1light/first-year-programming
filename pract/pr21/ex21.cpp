#include <iostream>
#include <stdlib.h>
#include <time.h>
#define col 8
#define row 10
        int main(){
            srand(time(0));
                int a[10][8] = {0};
                int j, i;
                bool jumper = false;
                i =  rand() % 10;
                j =  rand() % 8;
                a[i][j] = 1;
                    std::cout << i << " "<< j << std::endl;
                int i1, j1;
                int gamechecker = 0;


            while(gamechecker < 5){
                std::cin >> i1 >> j1;

                        if (i1 > 9 || j1 > 7 || i1 < 0 || j1 < 0 ){
                                std::cout << "za granicey" << "\n";

                        }
                        else if(a[i1][j1] == 1) {
                                std::cout << "vi viigrali" << "\n";
                                break;
                        }
                        else if(a[i1][j1] == 2){
                                std::cout << "ety yje proveryali" << "\n";
                        }
                        else if(a[i1][j1] != 1){
                                std::cout << "Net" <<std:: endl;
                                a[i1][j1] = 2;
                                ++gamechecker;
                        }


                if(gamechecker == 5) std::cout <<"GAME OVER";
             }
        return(0);
}
