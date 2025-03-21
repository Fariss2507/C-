#include <iostream>
using namespace std;

class Item {
protected:
    string name;
    int quantity;

public:
    void setItem(string n, int q) {
        name = n;
        quantity = q;
    }

    void displayItem() {
        cout << name << " (Quantity: " << quantity << ")" << endl;
    }
};

class BakedGoods : public Item {
protected:
    double discount = 0.10;
};

class Cakes : public BakedGoods {
public:
    double price = 600;

    double calculateBill() {
        return quantity * price * (1 - discount);
    }
};

class Bread : public BakedGoods {
public:
    double price = 200;

    double calculateBill() {
        return quantity * price * (1 - discount);
    }
};

class Drinks : public Item {
public:
    double price = 100;
    double discount = 0.05;

    double calculateBill() {
        return quantity * price * (1 - discount);
    }
};

int main() {
    int qCakes, qBread, qDrinks;
    cout << "Enter quantity of Cakes: ";// quantity of all items.....
    cin >> qCakes;
    cout << "Enter quantity of Bread: ";
    cin >> qBread;
    cout << "Enter quantity of Drinks: ";
    cin >> qDrinks;

    Cakes cake;
    cake.setItem("Cake", qCakes);
    Bread bread;
    bread.setItem("Bread", qBread);
    Drinks drink;
    drink.setItem("Drink", qDrinks);

    double totalBill = cake.calculateBill() + bread.calculateBill() + drink.calculateBill();

    cout << "\nBill Summary:\n";
    cake.displayItem();
    bread.displayItem();
    drink.displayItem();
    cout << "Total Bill: " << totalBill << " Rs" << endl;

    return 0;
}
