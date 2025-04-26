#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    int carId;
    string brand;
    string model;
    bool available;

public:
    Vehicle(int id, const string& br, const string& mo)
        : carId(id), brand(br), model(mo), available(true) {}

    virtual bool isAvailable() const = 0;
    virtual void rent() = 0;
    virtual void returnVehicle() = 0;
    virtual void displayInfo() const = 0;
    
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(int id, const string& br, const string& mo)
        : Vehicle(id, br, mo) {}

    bool isAvailable() const override {
        return available;
    }

    void rent() override {
        if (available) {
            available = false;
            cout << "Car rented successfully: " << brand << " " << model << endl;
        } else {
            cout << "Car is not available for rent.\n";
        }
    }

    void returnVehicle() override {
        available = true;
        cout << "Car returned successfully: " << brand << " " << model << endl;
    }

    void displayInfo() const override {
        cout << "Car ID: " << carId << ", Brand: " << brand << ", Model: " << model
             << ", Status: " << (available ? "Available" : "Rented") << endl;
    }
};

class RentalSystem {
public:
    void rentVehicle(Vehicle* v) {
        if (v->isAvailable()) {
            v->rent();
        } else {
            cout << "Vehicle is currently not available.\n";
        }
    }

    void returnVehicle(Vehicle* v) {
        v->returnVehicle();
    }
};

class Customer {
private:
    string name;

public:
    Customer(const string& n) : name(n) {}

    void rentVehicle(RentalSystem& system, Vehicle* v) {
        cout << name << " is trying to rent a vehicle...\n";
        system.rentVehicle(v);
    }

    void returnVehicle(RentalSystem& system, Vehicle* v) {
        cout << name << " is trying to return a vehicle...\n";
        system.returnVehicle(v);
    }
};

int main() {
    const int SIZE = 3;
    Vehicle* vehicles[SIZE];

    vehicles[0] = new Car(101, "Toyota", "Corolla");
    vehicles[1] = new Car(102, "Honda", "Civic");
    vehicles[2] = new Car(103, "Suzuki", "Swift");

    RentalSystem rentalSystem;
    Customer customer1("Ali");
    Customer customer2("Sara");

    cout << "\nAvailable Vehicles:\n";
    for (int i = 0; i < SIZE; ++i) {
        vehicles[i]->displayInfo();
    }

    cout << "\n--- Renting Operations ---\n";
    customer1.rentVehicle(rentalSystem, vehicles[0]);
    customer2.rentVehicle(rentalSystem, vehicles[0]);

    cout << "\nAvailable Vehicles After Renting:\n";
    for (int i = 0; i < SIZE; ++i) {
        vehicles[i]->displayInfo();
    }

    cout << "\n--- Returning Operations ---\n";
    customer1.returnVehicle(rentalSystem, vehicles[0]);
    customer2.rentVehicle(rentalSystem, vehicles[0]);

    cout << "\nAvailable Vehicles After Returning:\n";
    for (int i = 0; i < SIZE; ++i) {
        vehicles[i]->displayInfo();
    }

    for (int i = 0; i < SIZE; ++i) {
        delete vehicles[i];
    }

    return 0;
}
