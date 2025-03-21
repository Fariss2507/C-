#include <iostream>
using namespace std;

class BankAccount {
   private:
   double accountBalance = 100000;  // Initial balance

   public:
   int transactions = 0;

   void deposits(double dep) {
       cout << "You can deposit a maximum amount of 1,000,000 in a day.\n";
       if (dep > 1000000) {
           cout << "Deposit limit exceeded!" << endl;
           return;
       }
       accountBalance += dep;
       transactions++;
   }

   void withdrawal(double withdraw) {
       if (withdraw <= accountBalance) {  // Fixed condition
           accountBalance -= withdraw;
           transactions++;
       } else {
           cout << "You do not have that much cash.\n";
       }
   }

   void displayBalance() {  // Renamed for clarity
       cout << "Current Balance: " << accountBalance << endl;
   }

   void displayTransactions() {
       cout << "Today you have made " << transactions << " transactions." << endl;
   }
};

int main() {
    BankAccount u1;

    u1.deposits(5000);
    u1.displayBalance();

    u1.withdrawal(70000);
    u1.displayBalance();

    u1.displayTransactions();

    return 0;
}
