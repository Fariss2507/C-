#include <iostream>
using namespace std;


class Shape {
protected:
    int numberOfSides;
    double area;
public:
    Shape(int sides = 0) : numberOfSides(sides), area(0) {}

    void setArea(double a) 
    { area = a; }

    double getArea() 
    {
         return area; 
        }

    int getSides()
     {
         return numberOfSides; 
    }
};


class Rectangle : public Shape {
protected:
    double length, width;
public:
    Rectangle(double l, double w) : Shape(4), length(l), width(w) {}

    void generateArea() 
    {
        setArea(length * width);
    }
};


class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : Shape(1), radius(r) {}

    void generateArea()
     {

        setArea(3.14159 * radius * radius);

    }
};


class Triangle : public Shape {
private:
    double height, base;
public:
    Triangle(double h, double b) : Shape(3), height(h), base(b) {}

    void generateArea() {
        setArea((height * base) / 2);
    }
};


class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

    bool checkSides() {
        return length == width;
    }

    void generateArea() {
        setArea(length * length);
    }
};


int main() {
    Rectangle rect(4, 5);
    rect.generateArea();
    cout << "Rectangle Area: " << rect.getArea() << endl;

    Circle circle(3);
    circle.generateArea();
    cout << "Circle Area: " << circle.getArea() << endl;

    Triangle triangle(4, 6);
    triangle.generateArea();
    cout << "Triangle Area: " << triangle.getArea() << endl;

    Square square(4);
    square.generateArea();
    cout << "Square Area: " << square.getArea() << endl;
    cout << "Square sides equal? " << (square.checkSides() ? "Yes" : "No") << endl;
  // acha tw i have use ternary operator here......
    return 0;
}
