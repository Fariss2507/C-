# include<iostream>
using namespace std;

class Myclass{

public:
int *ptr;
Myclass(int val){
    ptr=new int(val);
}
Myclass (const Myclass & other){
    ptr=other.ptr;
}
void display(){
    cout<<"valyue is:"<<*ptr<<endl;
}

};

int main(){

    Myclass ob1(10);
    Myclass ob2=ob1;

 *ob2.ptr=20;
    ob1.display();
    ob2.display();
    return 0;
}