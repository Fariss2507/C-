# include<iostream>

using namespace std;

int count=0;
class num
{
    public:
    num()
    {
      count++;
      cout<<"This is the time when constructor is called for object number "<<count<<endl;

    }

    ~num() // acha tw destructor doesnt take arguments nor retutns a value
    {
cout<<" This is the time when destructor is called for object number "<<count<<endl;
  count--;

    }
};

int main()
{
cout<<"We are inside the main function"<<endl;
cout<<"Creating out first object n1 "<<endl;

num n1;
{
    cout<<"Entering in this this block"<<endl;
    cout<<"Creating two more objects i.e n2 and n3"<<endl;
    num n2, n3;
    cout<<"Exiting this block"<<endl;
}
cout<<"Back into the main function"<<endl;
return 0;
}