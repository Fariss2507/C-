#include <iostream>
using namespace std;


class Person {
protected:
    string occupation;
public:
    Person(string _occupation) : occupation(_occupation) {}

    void Draw() {
        cout << "A person can draw in many ways" << endl;
    }
};


class Artist : public Person {
public:
    Artist() : Person("artist") {}

    void Draw() {
        cout << "An artist can draw with a paint brush" << endl;
    }
};


class Gunman : public Person {
public:
    Gunman() : Person("gunman") {}

    void Draw()  {
        cout << "A gunman draws a gun to shoot" << endl;
    }
};


int main() {
  //  Person* people[2]; 

    //people[0] = new Artist(); 
   // people[1] = new Gunman(); 

    
  //  for (int i = 0; i < 2; i++) {
      //  people[i]->Draw();
      //  delete people[i]; 
   // }

   Artist a1;
   Gunman g1;

   a1.Draw();


   g1.Draw();

    return 0;
}
