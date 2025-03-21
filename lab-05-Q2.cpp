#include <iostream>
using namespace std;

class Teacher {
private:
    string name;
    int age;
    string institute;

public:
    void setTeacherDetails(string n, int a, string inst) {
        name = n;
        age = a;
        institute = inst;
    }

    string getName() 

    { return name; }
    int getAge()
     { return age; }
    
    string getInstitute() 
    { return institute; }

    void displayTeacherInfo() {
        cout << "Name " << name << endl;
        cout << "Age " << age << endl;
        cout << "Institute " << institute << endl;
    }
};

class HumanitiesTeacher : public Teacher {
private:
    string department = "Humanities";
    string courseName;
    string designation;

public:
    void setDetails(string course, string desig) {
        courseName = course;
        designation = desig;
    }

    void displayDetails() {
        displayTeacherInfo();
        cout << "Department:" << department << endl;
        cout << "Course:" << courseName << endl;
        cout << "Designation " << designation << endl;
        
    }
};

class ScienceTeacher : public Teacher {
private:
    string department = "Science";
    string courseName;
    string designation;

public:
    void setDetails(string course, string desig) {
        courseName = course;
        designation = desig;
    }

    void displayDetails() {
        displayTeacherInfo();
        cout << "Department " << department << endl;
        cout << "Course " << courseName << endl;
        cout << "Designation  " << designation << endl;
    
    }
};

class MathsTeacher : public Teacher {
private:
    string department = "Maths";
    string courseName;
    string designation;

public:
    void setDetails(string course, string desig) {
        courseName = course;
        designation = desig;
    }

    void displayDetails() {
        displayTeacherInfo();
        cout << "Department " << department << endl;
        cout << "Course " << courseName << endl;
        cout << "Designation " << designation << endl;
       
    }
};

int main() {
    string name, institute, course, designation;
    int age;

    HumanitiesTeacher hTeacher;
    cout << "Enter Humanities Teacher Details:\n";

    cout << "Name  ";
     cin >> name;
    cout << "Age: "; 
    cin >> age;
    
    cout << "Institute  "; 
    cin >> institute;
    cout << "Course  "; 
    cin >> course;
    cout << "Designation  ";
     cin >> designation;
    hTeacher.setTeacherDetails(name, age, institute);
    hTeacher.setDetails(course, designation);

    ScienceTeacher sTeacher;
    cout << "\nEnter Science Teacher Details:\n";
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
     cin >> age;
    cout << "Institute  "; 
    cin >> institute;
    cout << "Course  ";
     cin >> course;
    cout << "Designation  ";
     cin >> designation;
    sTeacher.setTeacherDetails(name, age, institute);
    sTeacher.setDetails(course, designation);

    MathsTeacher mTeacher;

    cout << "\nEnter Maths Teacher Details:\n";
    cout << "Name  "; 
    cin >> name;

    cout << "Age: "; 
    cin >> age;
    cout << "Institute  "; 
    cin >> institute;
    cout << "Course  ";
    cin >> course;
    cout << "Designation: "; 
    cin >> designation;
    mTeacher.setTeacherDetails(name, age, institute);
    mTeacher.setDetails(course, designation);

    
    hTeacher.displayDetails();
    sTeacher.displayDetails();
    mTeacher.displayDetails();

    return 0;
}
