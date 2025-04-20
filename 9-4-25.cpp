# include<iostream>
using namespace std;

class shape{

    public:

    virtual double area() const {
        return 0;

    }

    virtual double perimeter() const {
        return 0;
    }
    virtual void display() const {
        cout << "Shape: " << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }

};

class rectangle : public shape{

    private:
    double length;
    double width;

    public:
    rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }

    double perimeter() const override {
        return 2 * (length + width);
    }

    void display() const override {
        cout << "Rectangle: " << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        shape::display();
    }
};
class circle: public shape{

    private:
    double radius;

    public:
    circle(double r) : radius(r) {}

    double area() const override {
        return 3.14 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.14 * radius;
    }

    void display() const override {
        cout << "Circle: " << endl;
        cout << "Radius: " << radius << endl;
        shape::display();
    }
};

int main(){
    rectangle rect(5, 3);
    rect.display();

    circle circ(4);
    circ.display();

    return 0;
}