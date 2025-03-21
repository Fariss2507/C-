# include<iostream>
using namespace std;

class Base
{
    private:
   int data1;

    public:
   int data2;
   void setdata();
   int getdata1();
   int getdata2();


};
 
 void Base:: setdata(void){
    data1=10;
    data2=20;
 }

 int Base:: getdata1(){
    return data1;

 }
 int Base:: getdata2(){
return data2;
 }


class Derived : public Base{

int data3;
public:
 void process();
 void display();

};

void Derived:: process()
{
data3=  data2 * getdata1();   
//yaar yhn pr getdata() sy isliye multiply kia hy becaz data1 Base class main 
// private hy tw isliye hum directlty multiply nh krsktay kiu k hum usko inherit nh 
// krsktay.........                              

}
// kher back to code..
 void Derived:: display(){
     cout<<"The value of data1 is "<<getdata1()<<endl;
     cout<<"The value of data2 is "<<data2<<endl;
     cout<<"The value of data3 will be "<<data3<<endl;

 }

 int main(){
      
    Derived obj1;
     obj1.process();
     obj1.display();

     return 0;

 
 }