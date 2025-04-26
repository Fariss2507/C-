#include <iostream>
#include <string>
using namespace std;


class EncryptionTecnique {
public:
    virtual string encrypt(const string& message) = 0; 


class EncryptionTecnique1 : public EncryptionTecnique {
public:
    string encrypt(const string& message) override {
        string encrypted = "";
        for (char c : message) {
            encrypted += to_string(int(c));
        }
        return encrypted;
    }
};


class EncryptionTecnique2 : public EncryptionTecnique {
public:
    string encrypt(const string& message) override {
        string encrypted = "";
        for (char c : message) {
            encrypted += to_string(int(c) + 2);
        }
        return encrypted;
    }
};

int main() {
    string input;
    cout << "Enter a message to encrypt: ";
    getline(cin, input);

    EncryptionTecnique* technique1 = new EncryptionTecnique1();
    EncryptionTecnique* technique2 = new EncryptionTecnique2();

    string encrypted1 = technique1->encrypt(input);
    string encrypted2 = technique2->encrypt(input);

    cout << "Encrypted with Technique 1: " << encrypted1 << endl;
    cout << "Encrypted with Technique 2: " << encrypted2 << endl;

    delete technique1;
    delete technique2;

    return 0;
}
