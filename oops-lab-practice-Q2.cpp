#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

// Abstract class
class Person {
public:
    virtual void display() const = 0; // Pure virtual function
};

// Derived class
class Student : public Person {
private:
    string name;
    int marks;

public:
    Student(string n, int m) {
        name = n;
        if (m < 0 || m > 100) {
            throw invalid_argument("Marks should be between 0 and 100");
        }
        marks = m;
    }

    void display() const override {
        cout << "Student Name: " << name << ", Marks: " << marks << endl;
    }

    int getMarks() const {
        return marks;
    }

    string getName() const {
        return name;
    }
};

// Template class to display results
template <typename T>
class Result {
public:
    void showResult(const T& obj) {
        obj.display();
    }
};

int main() {
    try {
        map<string, int> studentMap;
        queue<Student> studentQueue;

        // Adding students
        Student s1("Ali", 85);
        Student s2("Sara", 90);
        Student s3("Zara", 75);

        // Map to store marks
        studentMap[s1.getName()] = s1.getMarks();
        studentMap[s2.getName()] = s2.getMarks();
        studentMap[s3.getName()] = s3.getMarks();

        // Queue to process
        studentQueue.push(s1);
        studentQueue.push(s2);
        studentQueue.push(s3);

        // Using template class
        Result<Student> r;

        cout << "\n--- Students in Queue ---\n";
        while (!studentQueue.empty()) {
            Student s = studentQueue.front();
            r.showResult(s);
            studentQueue.pop();
        }

        cout << "\n--- Students from Map ---\n";
        for (auto it : studentMap) {
            cout << it.first << " => " << it.second << endl;
        }

    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
