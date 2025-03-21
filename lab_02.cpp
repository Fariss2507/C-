# include<iostream>
using namespace std;

class Student{
   public:
   string name;
   int roll_no;
   int semester;
   string section;

   void display(){
     cout<<"Name is "<<name<<endl;
     cout<<"Roll no is "<<roll_no<<endl;
     cout<<"Is currently studing in   "<<semester<<" semester"<<endl;
     cout<<"Belong to Section  "<<section<<endl;
   } 

};
 int main(){

    Student s1, s2, s3, s4;

    s1.name="Fariss";
    s1.roll_no=183;
    s1.section="D";
    s1.semester=2;
     
    s2.name="Harry";
    s2.roll_no= 165;
    s2.section="A";
    s2.semester=7;

    s3.name="Ben";
    s3.roll_no=177;
    s3.section="A";
    s3.semester=6;

    s4.name="Alex";
    s4.roll_no=169;
    s4.section="F";
    s4.semester=1;

    cout<<"Students who are in section 'A ' are as follows:"<<endl<<endl;

    s2.display();

    s3.display();

   


return 0;
 }

