#include <iostream>
using namespace std;

class Store {
protected:
    float total_bill;

public:
    Store(float bill) : total_bill(bill) {}
    virtual float calculateFinalBill() = 0;
    virtual ~Store() {}
};

class ImtiazStore : public Store {
public:
    ImtiazStore(float bill) : Store(bill) {}

    float calculateFinalBill() override {
        return total_bill - (total_bill * 0.07);
    }
};

class BinHashimStore : public Store {
public:
    BinHashimStore(float bill) : Store(bill) {}

    float calculateFinalBill() override {
        return total_bill - (total_bill * 0.05);
    }
};

int main() {
    float bill;
    cout << "Enter the total bill amount: ";
    cin >> bill;

    Store* store1 = new ImtiazStore(bill);
    Store* store2 = new BinHashimStore(bill);

    cout << "Final bill at ImtiazStore (7% discount): " << store1->calculateFinalBill() << endl;
    cout << "Final bill at BinHashimStore (5% discount): " << store2->calculateFinalBill() << endl;

    delete store1;
    delete store2;

    return 0;
}
