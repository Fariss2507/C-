#include <iostream>
using namespace std;

class TollBooth {
private:
    int totalCars;        
    double totalMoney;   

public:
    
    TollBooth() {
        totalCars = 0;
        totalMoney = 0.0;
    }

    
    void CarsCrossing() {
        totalCars++;         
        totalMoney += 0.50;  
    }

    
   

  
    void displayTotals() const {
        cout << "Total Cars Passed: " << totalCars << endl;
        cout << "Total Money Collected: " << totalMoney << endl;
    }
};

int main() {
    TollBooth booth; 

    
    booth.CarsCrossing();
    booth.CarsCrossing();
    booth.CarsCrossing();
    booth.CarsCrossing();
    
    booth.CarsCrossing();
    

    booth.displayTotals();

    return 0;
}
