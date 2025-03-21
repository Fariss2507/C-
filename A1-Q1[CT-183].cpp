#include <iostream>
using namespace std;

class Radiator
{
private:
    string radiatorID;

public:
    Radiator(string id = "183")
    {
        radiatorID = id;
        cout << "Radiator is off" << endl;
    }

    string getRadiatorID()
    {
        return radiatorID;
    }

    void setRadiatorID(string id)
    {
        radiatorID = id;
    }

    void heats()
    {
        cout << "Radiator " << radiatorID << " is now heating." << endl;
    }
};

class Room
{
private:
    string roomName;
    int seatingCapacity;
    Radiator *radiators[2];
    int numRadiators;

public:
    Room(string name)
    {
        radiators[0] = nullptr;
        radiators[1] = nullptr;
        roomName = name;
        seatingCapacity = 12;
        numRadiators = 0;
        
    }

    string isHeatedBy(Radiator *radiator)
    {
        for (int i = 0; i < numRadiators; i++)
        {
            if (radiators[i]->getRadiatorID() == radiator->getRadiatorID())
            {
                return "Radiator already added to room.";
            }
        }
        if (numRadiators >= 2)
        {
            return "Cannot add Radiator. Room has a maximum number of radiators.";
        }
        radiators[numRadiators++] = radiator;
        return "Radiator successfully added to room.";
    }
};

int main()
{
    Room room("Living Room");
    Radiator rd1("183");
    Radiator rd2("183");

    cout << room.isHeatedBy(&rd1) << endl;
    cout << room.isHeatedBy(&rd2) << endl;

    rd1.heats();
    rd2.heats();

    return 0;
}
