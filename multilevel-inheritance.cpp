# include<iostream>
using namespace std;

class Student{

    protected:
    int roll_no;

    public:
    void set_roll_no(int);
    void get_roll_no(void);

};

void Student :: set_roll_no(int r){
    roll_no=r;
}
void Student :: get_roll_no(){
    cout<<"Your roll no is: "<<roll_no<<endl;

}
class Exam : public Student{
 public:
 int maths;
 int physics;
 int english;

 void set_marks(int , int , int );

};
void Exam :: set_marks(int m, int p, int e){
    maths=m;
    physics=p;
    english=e;
}

class Result: public Exam{
 
    public:
    float per;

    void display_result();

};
void Result :: display_result(){
    cout<<"Your roll no is: "<<roll_no<<endl;
    cout<<"Your maths marks are: "<<maths<<endl;
    cout<<"Your physics marks are: "<<physics<<endl;
    cout<<"Your english marks are: "<<english<<endl;
    cout<<"Your Result is: "<<(maths+physics+english)/3<<"%"<<endl;
}

int main(){

    Result fariss;
    fariss.set_roll_no(4730140);
    fariss.set_marks(97, 90, 80);
    fariss.display_result();
    return 0;
}