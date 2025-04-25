#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    string name;
    int level;
    int health;

public:
    Character(string n, int l, int h) : name(n), level(l), health(h) {}

    void display() {
        cout << "Name: " << name << "\nLevel: " << level << "\nHealth: " << health << endl;
    }
};

class Warrior : virtual public Character {
protected:
    int strength;

public:
    Warrior(string n, int l, int h, int str)
        : Character(n, l, h), strength(str) {}

    void slash() {
        cout << name << " performs a powerful Slash!" << endl;
    }

    void displayWarrior() {
        cout << "Strength: " << strength << endl;
    }
};

class Mage : virtual public Character {
protected:
    int intelligence;

public:
    Mage(string n, int l, int h, int intel)
        : Character(n, l, h), intelligence(intel) {}

    void fireball() {
        cout << name << " casts a massive Fireball!" << endl;
    }

    void displayMage() {
        cout << "Intelligence: " << intelligence << endl;
    }
};

class Archer : public Character {
protected:
    int dexterity;

public:
    Archer(string n, int l, int h, int dex)
        : Character(n, l, h), dexterity(dex) {}

    void rapidShot() {
        cout << name << " fires a Rapid Shot!" << endl;
    }

    void displayArcher() {
        cout << "Dexterity: " << dexterity << endl;
    }
};

class NPC : public Character {
public:
    NPC(string n, int l, int h) : Character(n, l, h) {}

    void talk() {
        cout << name << " says: 'Hello there! Welcome to our village.'" << endl;
    }
};

class Mighty : public Warrior, public Mage {
public:
    Mighty(string n, int l, int h, int str, int intel)
        : Character(n, l, h), Warrior(n, l, h, str), Mage(n, l, h, intel) {}

    void displayMighty() {
        display();
        displayWarrior();
        displayMage();
        cout << name << " is a Mighty warrior-mage hybrid!" << endl;
    }
};

int main() {
    Mighty mightyHero("EagleS", 20, 150, 90, 95);
    mightyHero.displayMighty();
    mightyHero.slash();
    mightyHero.fireball();

    cout << "\n";

    NPC villager(" Greg ", 1, 100);
    villager.display();
    villager.talk();

    return 0;
}
