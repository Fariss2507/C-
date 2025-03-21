#include <iostream>
using namespace std;

class Weapon {
public:
    void WeaponDescription() {
        cout << "Weapons are used in warfare" << endl;
    }
};

class HotWeapon : public Weapon {
public:
    void HotWeaponDescription() {
        cout << "Hot weapons use explosive materials like gunpowder for explosion" << endl;
    }
};

class Bomb : public HotWeapon {
public:
    void BombDescription() {
        cout << "Bombs are massive explosive devices that  cause destruction." << endl;
    }
};

class NuclearBomb : public Bomb {
public:
    void NuclearBombDescription() {
        cout << "Nuclear bombs works on the principle of fission and fussion. pakistan also has Nuclear bomb" << endl;
    }
};

int main() {
    NuclearBomb n;
    n.WeaponDescription();
    n.HotWeaponDescription();
    n.BombDescription();
    n.NuclearBombDescription();

    return 0;
}
