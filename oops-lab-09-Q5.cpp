#include <iostream>
#include <string>
using namespace std;

class EncryptionTecnique {
public:
    virtual string encrypt(const string& message) = 0;
    virtual ~EncryptionTecnique() {}
};

class DecryptionTecnique {
public:
    virtual string decrypt(const string& encryptedMessage) = 0;
    virtual ~DecryptionTecnique() {}
};

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

class DecryptionTecnique1 : public DecryptionTecnique {
public:
    string decrypt(const string& encryptedMessage) override {
        string decrypted = "";
        for (size_t i = 0; i < encryptedMessage.length(); ) {
            string ascii_code = encryptedMessage.substr(i, 2);
            char ch = static_cast<char>(stoi(ascii_code));
            decrypted += ch;
            i += 2;
        }
        return decrypted;
    }
};

class DecryptionTecnique2 : public DecryptionTecnique {
public:
    string decrypt(const string& encryptedMessage) override {
        string decrypted = "";
        for (size_t i = 0; i < encryptedMessage.length(); ) {
            string ascii_code = encryptedMessage.substr(i, 2);
            char ch = static_cast<char>(stoi(ascii_code) - 2);
            decrypted += ch;
            i += 2;
        }
        return decrypted;
    }
};

int main() {
    string input;
    cout << "Enter a message to encrypt: ";
    getline(cin, input);

    EncryptionTecnique* technique1 = new EncryptionTecnique1();
    EncryptionTecnique* technique2 = new EncryptionTecnique2();
    DecryptionTecnique* decrypt1 = new DecryptionTecnique1();
    DecryptionTecnique* decrypt2 = new DecryptionTecnique2();

    string encrypted1 = technique1->encrypt(input);
    string encrypted2 = technique2->encrypt(input);

    cout << "\nEncrypted with Technique 1: " << encrypted1 << endl;
    cout << "Encrypted with Technique 2: " << encrypted2 << endl;

    cout << "\nDecrypting..." << endl;
    cout << "Decrypted from Technique 1: " << decrypt1->decrypt(encrypted1) << endl;
    cout << "Decrypted from Technique 2: " << decrypt2->decrypt(encrypted2) << endl;

    delete technique1;
    delete technique2;
    delete decrypt1;
    delete decrypt2;

    return 0;
}
