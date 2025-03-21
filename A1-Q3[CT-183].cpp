# include<iostream>
using namespace std;

class HeartRates{
    private:
    string first_name;
    int Id;
    string date_of_birth;
    int current_year;
    int age;

    public:
    HeartRates(string f_name, string dob, int c_year){
        first_name=f_name;
        date_of_birth=dob;
        current_year=c_year;
    }
    void setFirstName(string f_name){
        first_name=f_name;
    }
    void setDOB(string dob){
        date_of_birth=dob;
    }
    void setYear(int c_year){
        current_year=c_year;
    }
    void setId(int id){
        Id=id%10;

    }

    void calc_age() {
        age = current_year - ((date_of_birth[6] - '0') * 1000 + (date_of_birth[7] - '0') * 100 +
                              (date_of_birth[8] - '0') * 10 + (date_of_birth[9] - '0'));
    }
    // so first we will convert dob into integer than perform calculation......
   
    string __get_first_name(){
        return first_name;
    }
    string __get_dob(){
        return date_of_birth;
    }
    int __get_year(){
        return current_year;
    }
    int __get_age(){
        return age;
    }
    int __get_id(){
        return Id;
    }
    void display(){
        cout<<"First Name  "<<first_name<<endl;
        cout<<"Date of Birth  "<<date_of_birth<<endl;
        cout<<"Current Year  "<<current_year<<endl;
        cout<<"Age  "<<age<<" Years"<<endl;
        cout<<"ID  "<<Id<<endl;
    }
    void calc_max_heart_rate(void){
        cout<<"Maximum Heart Rate: "<<220-age<<endl;
    }
    void calc_target_heart_rate(void){
        cout<<"Target Heart Rate: "<<(220-age)*0.85<<" to "<<(220-age)*0.5<<endl;
    }
   // void display_heart_rate(){
      //  cout<<"Target Heart Rate: "<<(220-age)*0.85<<" to "<<(220-age)*0.5<<endl;
   // }

};
int main(){
    HeartRates h1("Fariss", "25/07/2006", 2025);
    h1.setId(183);
    h1.calc_age();
    h1.display();
    h1.calc_max_heart_rate();
    h1.calc_target_heart_rate();
    return 0;
}