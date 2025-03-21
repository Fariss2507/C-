#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    double x, y;

public:
    
    Vector(double xVal, double yVal) : x(xVal), y(yVal) {}

   
    Vector operator+(const Vector& v) {
        return Vector(x + v.x, y + v.y);
    }

    
    Vector operator-(const Vector& v) {
        return Vector(x - v.x, y - v.y);
    }

    
    Vector operator*(double scalar) {
        return Vector(x * scalar, y * scalar);
    }

    
    Vector operator/(double scalar) {
        if (scalar == 0) {
            cout << "infinity ajaega" << endl;
            return *this; 
        }
        return Vector(x / scalar, y / scalar);
    }
 
    double magnitude() {
        return sqrt(x * x + y * y);
    }

    
    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};


int main() {
    Vector v1(3, 4);
    Vector v2(1, 2);

    cout << "Vector 1: ";
    v1.display();
    cout << "Vector 2: ";
    v2.display();

    Vector sum = v1 + v2;
    cout << "Sum: ";
    sum.display();

    Vector diff = v1 - v2;
    cout << "Difference: ";
    diff.display();

    Vector scaled = v1 * 2;
    cout << "Scaled (v1 * 2): ";
    scaled.display();

    Vector divided = v1 / 2;
    cout << "Divided (v1 / 2): ";
    divided.display();

    cout << "Magnitude of Vector 1: " << v1.magnitude() << endl;
    cout << "Magnitude of Vector 2: " << v2.magnitude() << endl;

    return 0;
}
