#include <iostream>
using namespace std;

class Complex
{

private:
    int *real;
    int *imag;

public:
    Complex(int r, int i)
    {

        real = new int(r);
        imag = new int(i);
    }

    Complex(const Complex &obj)
    {
        real = new int(*(obj.real));
        imag = new int(*(obj.imag));
    }

    void display(void)
    {
        cout << *real << " + " << *imag << "i" << endl;
    }
    ~Complex()
    {
        delete real;
        delete imag;
    }
};

int main()
{
    Complex c1(5, 7);
    Complex c2 = c1;

    c1.display();
    c2.display();
    return 0;
}