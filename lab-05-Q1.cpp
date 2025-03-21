#include <iostream>
using namespace std;

class Base {
private:
    int privateInt;
protected:
    int protectedInt;
public:
    int publicInt;

    void setPrivateInt(int value) 
    { 
        privateInt = value;
    }

    int getPrivateInt() 
    {
         return privateInt;

         }

    void setProtectedInt(int value)
     { 
        protectedInt = value; 

    }
    int getProtectedInt()
     { return protectedInt; 

    }
};

class PublicChild : public Base {
public:
    void show() {
        cout << "This is Public child: " << endl;
        cout << "privateInt " << getPrivateInt() << endl;
        cout << "protectedInt " << protectedInt << endl;
        cout << "publicInt " << publicInt << endl;
    }
};

class ProtectedChild : protected Base {
public:
    void show() {
        cout << "This is Ptotected child  " << endl;
        cout << "privateInt " << getPrivateInt() << endl;
        cout << "protectedInt " << protectedInt << endl;
        cout << "publicInt " << publicInt << endl;
    }
};

class PrivateChild : private Base {
public:
    void show() {
        cout << "This is priavet chi " << endl;
        cout << "privateInt " << getPrivateInt() << endl;
        cout << "protectedInt " << protectedInt << endl;
        cout << "publicInt " << publicInt << endl;
    }
};

int main() {
    PublicChild obj1;
    obj1.setPrivateInt(100);
    obj1.setProtectedInt(240);
    obj1.publicInt = 130;
    obj1.show();
    
    ProtectedChild obj2;
    obj2.setPrivateInt(340);
    obj2.setProtectedInt(650);
    obj2.show();
    
    PrivateChild obj3;
    obj3.setPrivateInt(709);
    obj3.setProtectedInt(890);
    obj3.show();

    return 0;
}
