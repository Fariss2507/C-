#include <iostream>
#include <string>

using namespace std;

class DataScientist
{
public:
    int id;
    string first_name, last_name, country;
    int age;
    int answers_given=0,  questions_asked=0;
    string highest_education;

    DataScientist( string f_name, string l_name, int a, string c, string edu)
    {
        
        first_name = f_name;
        last_name = l_name;
        age = a;
        country = c;
        highest_education = edu;
        answers_given = 0;
        questions_asked = 0;
    }
    void set_roll_no(int roll_no)
    {
        id = roll_no % 100;
    }

    void askQuestion()
    {
        questions_asked++;
    }

    void answerProblem()
    {
        answers_given++;
    }

    void display()
    {
        cout << "Data Scientist ID  " <<id<< " \nFirst Name "<<first_name<<"\nLast Name "<<last_name <<"\nHighest Education "<<highest_education<< "\nQuestions Asked " << questions_asked
         << "\nAnswers Given " << answers_given << endl<<endl;
    }
};

class Admin
{
public:
    static int admin_count;
    int admin_id;
    string first_name, last_name, country;
    int age, total_users;

    Admin(string f_name, string l_name, int a, string c)
    {
        first_name = f_name;
        last_name = l_name;
        age = a;
        country = c;
        admin_id = ++admin_count; // this is how i made unique id.....
        total_users = 0;
    }

    void createUser()
    {
        total_users++;
    }

    void display()
    {
        cout << "Admin ID " << admin_id << "\nTotal Users Created  " << total_users << endl;
    }
};

int Admin::admin_count = 0;

int main()
{
    DataScientist ds1("Dr Hikaru ", "Nakamura", 37, "America", "PhD");
    ds1.set_roll_no(183);
    ds1.askQuestion();
    ds1.answerProblem();
    ds1.answerProblem();
    ds1.display();
    DataScientist ds2("Dr Magnus", "Carlsen", 30, "Norway", "PhD");
    ds2.set_roll_no(183);
    ds2.askQuestion();
    ds2.askQuestion();
    ds2.askQuestion();
    ds2.answerProblem();
    ds2.display();

    Admin admin1("Gukesh", "Dommaraju", 18, "India");
    admin1.createUser();
    admin1.createUser();
    admin1.display();

    return 0;
}
