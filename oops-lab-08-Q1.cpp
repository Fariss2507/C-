#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string type, make, model, color;
    int year;
    double milesDriven;

public:
    Vehicle(string t, string ma, string mo, string c, int y, double miles)
        : type(t), make(ma), model(mo), color(c), year(y), milesDriven(miles) {}

    void display() {
        cout << "Type: " << type << "\nMake: " << make << "\nModel: " << model
             << "\nColor: " << color << "\nYear: " << year << "\nMiles Driven: " << milesDriven << endl;
    }
};

class GasVehicle : virtual public Vehicle {
protected:
    double fuelTankSize;

public:
    GasVehicle(double fuel) : fuelTankSize(fuel) {}

    void displayGas() {
        cout << "Fuel Tank Size: " << fuelTankSize << " liters" << endl;
    }
};

class ElectricVehicle : virtual public Vehicle {
protected:
    double energyStorage;

public:
    ElectricVehicle(double energy) : energyStorage(energy) {}

    void displayElectric() {
        cout << "Energy Storage: " << energyStorage << " kWh" << endl;
    }
};

class HeavyVehicle : public GasVehicle, public ElectricVehicle {
protected:
    double maxWeight;
    int numWheels;
    double length;

public:
    HeavyVehicle(double fuel, double energy, double weight, int wheels, double len)
        : GasVehicle(fuel), ElectricVehicle(energy),
          maxWeight(weight), numWheels(wheels), length(len) {}

    void displayHeavy() {
        cout << "Max Weight: " << maxWeight << " tons"
             << "\nNumber of Wheels: " << numWheels
             << "\nLength: " << length << " meters" << endl;
    }
};

class Bus : public HeavyVehicle {
private:
    int numberOfSeats;

public:
    Bus(string t, string ma, string mo, string c, int y, double miles,
        double fuel, double energy, double weight, int wheels, double len, int seats)
        : Vehicle(t, ma, mo, c, y, miles),
          HeavyVehicle(fuel, energy, weight, wheels, len),
          numberOfSeats(seats) {}

    void displayBus() {
        display();
        displayGas();
        displayElectric();
        displayHeavy();
        cout << "Number of Seats: " << numberOfSeats << endl;
    }
};

int main() {
    Bus myBus("Bus", "Toyota", "Coaster", "White", 2022, 35000,
              80, 0, 7.5, 6, 8, 30);

    myBus.displayBus();

    return 0;
}
