#include <iostream>
using namespace std;

class Account {
protected:
    double balance;

public:
    Account() {
        cin >> balance;
    }

    Account(double b) : balance(b) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
    }

    virtual void checkBalance() {
        cout << "Current Balance: " << balance << endl;
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double b) {
        balance = b;
    }
};

class InterestAccount : virtual public Account {
protected:
    double interest;

public:
    InterestAccount() : Account(), interest(0.3) {}

    InterestAccount(double b) : Account(b), interest(0.3) {}

    void deposit(double amount) override {
        double interestAmount = amount * interest;
        balance += amount + interestAmount;
    }
};

class ChargingAccount : virtual public Account {
protected:
    double fee;

public:
    ChargingAccount() : Account(), fee(25) {}

    ChargingAccount(double b) : Account(b), fee(25) {}

    void withdraw(double amount) override {
        if ((amount + fee) <= balance)
            balance -= (amount + fee);
    }
};

class ACI : public InterestAccount, public ChargingAccount {
public:
    ACI() : InterestAccount(), ChargingAccount() {}

    ACI(double b) : InterestAccount(b), ChargingAccount(b) {}

    void transfer(double amount, Account &acc) {
        if (balance >= amount) {
            balance -= amount;
            acc.deposit(amount);
        }
    }

    void showBalance() {
        checkBalance();
    }
};

int main() {
    ACI myAccount(1000);
    InterestAccount interestAcc(500);
    ChargingAccount chargingAcc(500);

    interestAcc.deposit(200);
    chargingAcc.withdraw(100);
    myAccount.transfer(300, interestAcc);
    myAccount.transfer(100, chargingAcc);

    return 0;
}
