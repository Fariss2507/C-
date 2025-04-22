# include<iostream>

using namespace std;

class Base{
    protected:
    int a=15;

    private :
    int b;

     public:
     void dis(int x){
        a=x;
     }

};
class Derived : public Base{
    public:
 Derived(int n1){
    a=n1;

}
    int getA() const {
        return a;
    }

    5*
};

int main()
{

    
 Derived b1(100);
    cout<<b1.getA()<<endl;
    return 0;
}
