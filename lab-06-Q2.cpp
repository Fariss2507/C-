#include <iostream>
using namespace std;

class Calculator {
private:
    double Num1, Num2, Num3;

public:
    
    Calculator() {
        cout << "Enter three numbers: ";
        cin >> Num1 >> Num2 >> Num3;
    }

   
    double add(double a, double b) {
        return a + b;
    }

    double add(double a, double b, double c) {
        return a + b + c;
    }

    
    double multiply(double a, double b)
     {
        return a * b;
    }

    double multiply(double a, double b, double c)
     {
        return a * b * c;
    }

    
    double subtract(double a, double b) 
    {
        return a - b;
    }

  
    double divide(double a, double b)
    {
         
        
        return a / b;
    }

    
    void demonstrate() {
        cout << "Addition of 2 numbers " << add(Num1, Num2) << endl;
        cout << "Addition of 3 numbers " << add(Num1, Num2, Num3) << endl;

        cout << "Multiplication of 2 numbers " << multiply(Num1, Num2) << endl;
        cout << "Multiplication of 3 numbers " << multiply(Num1, Num2, Num3) << endl;

        cout << "Subtraction: " << subtract(Num1, Num2) << endl;
        cout << "Division: " << divide(Num1, Num2) << endl;
    }
};


int main() {
    Calculator calc;
    calc.demonstrate();
    return 0;
}
