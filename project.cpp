# include<iostream>
using namespace std;

class simplecalc{
    private:
    int a;
    int b;
    int result1;
    int result2;
    int result3;
    int result4;
    public:
    void set_values(int val1, int val2){
        a=val1;
        b=val2;
    }
    void process(){
        result1=a+b;
        result2=a-b;
        result3=a*b;
        result4=a/b;

    }
    void print(){
        cout<<"The addition of two nos  is "<<result1<<endl;
        cout<<"The subtraction of two nos  is "<<result2<<endl;
        cout<<"The multiplication of two nos  is "<<result3<<endl;
        cout<<"The division of two nos  is "<<result4<<endl;
    }
  //  void add();
   // void sub();
   // void mul();
   // void div();
   // void display();
};
int main(){
    simplecalc obj;
    obj.set_values(10, 20);
    obj.process();
    obj.print();
    return 0;
}