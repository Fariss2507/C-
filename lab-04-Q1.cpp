#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Employee {
private:
    char* employeeName;
    const int employeeID;

public:
    
    Employee(const char* name, int id) : employeeID(id) {
        employeeName = new char[strlen(name) + 1];
        strcpy(employeeName, name);
    }

    
    ~Employee() {
        delete[] employeeName;
    }

    
    void setEmployeeName(const char* name) {
    
        employeeName = new char[strlen(name) + 1];
        strcpy(employeeName, name);
    }

   
    const char* getEmployeeName() const {
        return employeeName;
    }

    
    int getEmployeeID() const {
        return employeeID;
    }
};

int main() {
    
    Employee employee1("Fariss Faheem", 1);
    Employee employee2("Ali Ahmed", 2);
    Employee employee3("Gotham ", 3);

    cout<<"names before changing"<<endl;
    cout  << employee1.getEmployeeName() << " ID: " << employee1.getEmployeeID() << endl;
    cout  << employee2.getEmployeeName() << " ID: " << employee2.getEmployeeID() << endl;
    cout  << employee3.getEmployeeName() << " ID: " << employee3.getEmployeeID() << endl;

    employee1.setEmployeeName("Magnus Carlson");
    employee2.setEmployeeName("Hikaru Nakamura");
    employee3.setEmployeeName("Gukesh D");

    cout<<"names after changing"<<endl;
    cout <<   employee1.getEmployeeName() <<" ID: " << employee1.getEmployeeID() << endl;
    cout  << employee2.getEmployeeName() << " ID: " << employee2.getEmployeeID() << endl;
    cout  << employee3.getEmployeeName() << " ID: " << employee3.getEmployeeID() << endl;

    return 0;
}