# include<iostream>

using namespace std;

class Date{
    int month;
    int day;
    int year;
    public:
    Date(int m, int d, int y){
        month=m;
        day=d;
        year=y;
    }

    int setmonth(){
        if(month>=1 && month<=12){
            return month;
        }
        else{
           return  month==1;
        }
    }
    int setday(){
        return day;
    }
    int setyear(){
        return year;
    }
   // void getmonth(){
 // cout<<"Month is "<<month<<endl;
  //  }
    void getday(){
        cout<<"Day is"<<day<<endl;
    }
    void getyear(){
        cout<<"Year is "<< year<<endl;
    }
    void displayDate(void){
        cout<<"The date is "<<month<<"/"<<day<<"/"<<year<<endl;
    }
};
int main(){

    Date t1(32, 12, 2025);
   // t1.getmonth();
    t1.getday();
    t1.getyear();
    t1.displayDate();
    return 0;
}