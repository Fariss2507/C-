#include <iostream>
using namespace std;

class BankAccount
{
private:
   double accountBalance = 0;

public:
   int transactions = 0;

   void deposits(double dep)
   {
      cout << "You can deposit a maximum amount of 1000000 in a day." << endl;
      if (dep > 1000000)
      {
         cout << "Deposit limit exceeded!" << endl;
         return;
      }
      accountBalance += dep;
      transactions++;
   }

   void displayBalance()
   {
      cout << "Current Balance: " << accountBalance << endl;
   }

   void withdrawal(double withdraw)
   {
      if (withdraw <= accountBalance)
      {
         accountBalance -= withdraw;
         transactions++;
      }
      else
      {
         cout << "You don't have that much cash." << endl;
      }
   }

   void displayTransactions()
   {
      cout << "Today you have made " << transactions << " transactions." << endl;
   }

   void exitProgram()
   {
      cout << "Exiting the program..." << endl;
   }
};

int main()
{
   BankAccount u1;
   int choice;
   double amt;

   while (true)
   {
      /* acha yahan pr while loop true isliye lia becaz loop infinite time chlta rahy*/
      cout << "Select an option: \n"
           << "1. Display account balance\n"
           << "2. Number of transactions\n"
           << "3. Make a deposit\n"
           << "4. Make a withdrawal\n"
           << "5. Exit the program" << endl;
      cin >> choice;

      switch (choice)
      {
      case 1:
         u1.displayBalance();
         break;
      case 2:
         u1.displayTransactions();
         break;
      case 3:
         cout << "Enter deposit amount: ";
         cin >> amt;
         u1.deposits(amt);
         break;
      case 4:
         cout << "Enter withdrawal amount: ";
         cin >> amt;
         u1.withdrawal(amt);
         break;
      case 5:
         u1.exitProgram();
         return 0;
      default:
         cout << "Invalid choice." << endl;
      }
   }
   return 0;
}
