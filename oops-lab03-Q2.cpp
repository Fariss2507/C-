#include <iostream>
#include <string>
using namespace std;

class Character {
private:
    string name;
    int* health;
    int* attackPower;
    int* defense;

public:
    Character() {
        name = "Underworld Demon";
        health = new int(100);
        attackPower = new int(10);
        defense = new int(5);
    }

    
    Character(string n, int h, int atk, int def) {
        name = n;
        health = new int(h);
        attackPower = new int(atk);
        defense = new int(def);
    }

 
    Character(const Character& other) {
        name = other.name;
        health = new int(*(other.health));
        attackPower = new int(*(other.attackPower));
        defense = new int(*(other.defense));
    }

    string getName() const
    { return name; }

    int getHealth() const
     { return *health; }

    int getAttackPower() const
     { return *attackPower; }

    int getDefense() const 
    { return *defense; }

   
    void setName(string n)
     { name = n; }
    void setHealth(int h)
     { *health = h; }
    void setAttackPower(int atk) 
    { *attackPower = atk; }
    void setDefense(int def)
     { *defense = def; }


    void displayCharacter() const {
        cout << "Character: " << name << endl;
        cout << "Health: " << *health << endl;
        cout << "Attack Power: " << *attackPower << endl;
        cout << "Defense: " << *defense << endl;
      
    }

    ~Character() {
        delete health;
        delete attackPower;
        delete defense;
    }
};

int main() {

    Character player1;
    player1.displayCharacter();

    
    Character player2("Dare Devil", 150, 20, 10);
    player2.displayCharacter();

    Character player3 = player2; 
    player3.setName("Slayer Devil"); 
    player3.displayCharacter();

    return 0;
}
