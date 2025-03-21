#include <iostream>
using namespace std;

class Hotel_rent
{
private:
    string customer_name;
    int days;
    const float rent_per_day = 1000.85;

public:
    Hotel_rent(string name, int day)
    {
        customer_name = name;
        days = day;
    }
    float calculate_rent()
    {
        if(days>7){
            return (days-1)* rent_per_day;

        }
        else 
        return days * rent_per_day;

    }
    void printInfo(void){
        cout<<"The Customer Name is: "<<customer_name<<endl;
        cout<<"The number of days stayed by "<<customer_name<< " are: "<<days<<endl;
        cout<<"The total rent is: "<<calculate_rent()<<endl;
    }
};

int main(){
    Hotel_rent h1("Fariss", 10);
    h1.printInfo();
    return 0;
}