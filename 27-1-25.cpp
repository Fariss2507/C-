# include<iostream>
using namespace std;

class AddAmount
{

private:
long amount=50; // so initial amount is 50$........

public:
AddAmount(){
cout<<"This is the default constructor"<<endl;
}

AddAmount(int num)
{
    amount= 50 +num;

}
void display(){

    cout<<"amount After adding the new amount will be  "<<amount<<"$"<<endl;
}

};

int main()

{
    AddAmount a(); 
  AddAmount b(1000);
  b.display();
  return 0;

}