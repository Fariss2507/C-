# include<iostream>
# include<cstring>
# include<string>


using namespace std;
class Employee{

private:
char* firstname;
string lastname;
int monthlysalary;

public:
void setfirstname(const char* fname){
firstname= new char [strlen(fname)+1];
strcpy(firstname, fname);

}

void setlastname(string lname){
    lastname=lname;
}
void setsalary(int salary )
{
    if(salary>0){
        monthlysalary= salary;
    }
    else
    salary=0;
}   

const char* getfirstname(){
    return firstname;
}

 string getlastname(){
    return lastname;
}

 int getsalary(){
    return monthlysalary;

}

int getearlysalary(){
 return monthlysalary*12;
}

void risingSalary(){
    monthlysalary+= monthlysalary*0.10;

}

void displayinfo(){
   // cout<<"First name is: "<<getfirstname()<<endl;
   // cout<<"Last name is:  "<<getlastname()<<endl;
   // cout<<"Monthly salary is:  "<<getsalary()<<endl;
    //cout<<"Yearly salary will be:  "<<getyearlysalary()
    cout<<"Employee name : "<<firstname<<" "<<lastname<<endl;
    cout<<"Monthly salary: "<<monthlysalary<<endl;
    cout<<"Yearly salary will be: "<<getearlysalary()<<endl<<endl;
}
void freeMemory(){
    delete[] firstname; // becaz humny first name ko DMA kia tha tw  usko free bhi krna parega...
}

};

int main(){

    Employee e1, e2;
    e1.setfirstname("John");
    e1.setlastname("Dalton");
    e1.setsalary(100000);

    e2.setfirstname("Neil");
    e2.setlastname("Down");
    e2.setsalary(30000);

    e1.displayinfo();
    e2.displayinfo();//before salary raise.......


e1.risingSalary();
    e2.risingSalary();


    cout<<"After the salary raise of both will be:)  "<<endl<<endl;

    e1.displayinfo();
    e2.displayinfo();

    


    return 0;
}
