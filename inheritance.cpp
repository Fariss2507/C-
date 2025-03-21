#include <iostream>
using namespace std;

class Employee
{

public:
    int id;
    double salary;

    Employee(int inpid)
    {
        id = inpid;
        salary=3000;
        cout<<"Salary of employee will be"<<salary<<endl;
        cout<<"Employee Id is"<<id<<endl;
    }
    Employee(){}
};

class Programmer : public Employee
{
public:
/* so basically inheritance ka faida ye hua k hamen derived class main
wapis sy integer ID member include nh krna para just simply function bnadia*/
    int languagecode;

    Programmer(int inpid)
    {
        id = inpid;
        languagecode = 10;
        salary=10000;
        cout<<"The salary of Programmer will be"<<salary<<endl;
        cout<<"Programmer ID is"<<id<<endl;
        cout<<"Language code is"<<languagecode<<endl;
    }
    // cout<<id<<endl;
    void getData(){
        cout<<languagecode<<endl;


    }
};

int main()
{
    Employee fariss(1), ben(2);
    cout<<fariss.salary<<endl;
    cout<<ben.salary<<endl;
    Programmer skill(9);
    skill.getData();

    return 0;


}