#include <iostream>
using namespace std;

class Circle {
private:
    const float PI = 3.14159; 
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float calculateArea() const { 
        float area = PI * radius * radius;
        cout << "Area of circle: " << area << endl;
    }
};

int main() {
    Circle c1(5); 
    c1.calculateArea(); 
    return 0;
}
