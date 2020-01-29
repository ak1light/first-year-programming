#include <iostream>

    double BMI(double weight, double height);
    void printBMI(double BMI);
    int main(){

        double weight, height, BMI1;
        std::cin >> weight >> height;
        BMI1 = BMI(weight, height);
        printBMI(BMI1);
    return(0);
}
    double BMI(double weight, double height){
        return(weight / ((height/100)*(height/100)));
    }
    void printBMI(double BMI1){

        if(BMI1 < 18.5) std::cout << "Underweight";
        else if(18.5 <= BMI1 && BMI1 < 25.0) std::cout << "Normal weight";
        else if(25.0 <= BMI1 && BMI1 < 30.0) std::cout << "Overweight";
        else if(30.0 <= BMI1) std::cout <<"Obesity";
    }

