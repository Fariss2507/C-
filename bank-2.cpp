#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount
{
protected:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string holder, int accNum, double bal)
        : accountHolder(holder), accountNumber(accNum), balance(bal) {}

    virtual void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: $" << amount << " | New Balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount!\n";
        }
    }

    virtual void withdraw(double amount) = 0;

    virtual void displayAccountDetails()
    {
        cout << "\nAccount Holder: " << accountHolder;
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nBalance: $" << balance << endl;
    }

    double getBalance() { return balance; }
    int getAccountNumber() { return accountNumber; }

    virtual ~BankAccount() {}
};
class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(string holder, int accNum, double bal, double rate)
        : BankAccount(holder, accNum, bal), interestRate(rate) {}

    void withdraw(double amount) override
    {
        if (amount > 0 && balance - amount >= 500)
        {
            balance -= amount;
            cout << "Withdrawn: $" << amount << " | New Balance: $" << balance << endl;
        }
        else
        {
            cout << "Insufficient funds or minimum balance limit!\n";
        }
    }

    void applyInterest()
    {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest Applied: $" << interest << " | New Balance: $" << balance << endl;
    }

    void displayAccountDetails() override
    {
        BankAccount::displayAccountDetails();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};
class CurrentAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CurrentAccount(string holder, int accNum, double bal, double overdraft)
        : BankAccount(holder, accNum, bal), overdraftLimit(overdraft) {}

    void withdraw(double amount) override
    {
        if (amount > 0 && balance - amount >= -overdraftLimit)
        {
            balance -= amount;
            cout << "Withdrawn: $" << amount << " | New Balance: $" << balance << endl;
        }
        else
        {
            cout << "Withdrawal exceeds overdraft limit!\n";
        }
    }

    void displayAccountDetails() override
    {
        BankAccount::displayAccountDetails();
        cout << "Overdraft Limit: $" << overdraftLimit << "\n";
    }
};
class Bank
{
private:
    vector<BankAccount *> accounts;

public:
void displayAccountDetails() override
    {
        BankAccount::displayAccountDetails();
        cout << "Overdraft Limit: $" << overdraftLimit << "\n";
    }
    void createAccount()
    {
        string name;
        int accNum, type;
        double balance, rate, overdraft;

        cout << "\nEnter Account Holder Name: ";
        cin >> name;
        cout << "Enter Account Number: ";
        cin >> accNum;
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cout << "Select Account Type (1. Savings 2. Current): ";
        cin >> type;

        if (type == 1)
        {
            cout << "Enter Interest Rate (%): ";
            cin >> rate;
            accounts.push_back(new SavingsAccount(name, accNum, balance, rate));
            cout << "Savings Account Created Successfully!\n";
        }
        else if (type == 2)
        {
            cout << "Enter Overdraft Limit: ";
            cin >> overdraft;
            accounts.push_back(new CurrentAccount(name, accNum, balance, overdraft));
            cout << "Current Account Created Successfully!\n";
        }
        else
        {
            cout << "Invalid Account Type!\n";
        }
    }

    BankAccount *findAccount(int accNum)
    {
        for (auto &acc : accounts)
        {
            if (acc->getAccountNumber() == accNum)
            {
                return acc;
            }
        }
        return nullptr;
    }

    void depositMoney()
    {
        int accNum;
        double amount;
        cout << "\nEnter Account Number: ";
        cin >> accNum;
        BankAccount *acc = findAccount(accNum);
        if (acc)
        {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            acc->deposit(amount);
        }
        else
        {
            cout << "Account not found!\n";
        }
    }

    void withdrawMoney()
    {
        int accNum;
        double amount;
        cout << "\nEnter Account Number: ";
        cin >> accNum;
        BankAccount *acc = findAccount(accNum);
        if (acc)
        {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            acc->withdraw(amount);
        }
        else
        {
            cout << "Account not found!\n";
        }
    }

    void transferMoney()
    {
        int fromAcc, toAcc;
        double amount;
        cout << "\nEnter Sender's Account Number: ";
        cin >> fromAcc;
        cout << "Enter Receiver's Account Number: ";
        cin >> toAcc;
        cout << "Enter Amount to Transfer: ";
        cin >> amount;
    }
};
int main()
{
    Bank bank;
    int choice;

    do
    {
        cout << "\n=== BANKING SYSTEM MENU ===";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Transfer Money";
        cout << "\n5. Display All Accounts";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;
        case 2:
            bank.depositMoney();
            break;
        case 3:
            bank.withdrawMoney();
            break;
        case 4:
            bank.transferMoney();
            break;
        case 5:
            bank.displayAllAccounts();
            break;
        case 6:
            cout << "Exiting... Thank you!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
