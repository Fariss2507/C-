# include<iostream>
using namespace std;

class Account{
    private:
 int account_no;
 int account_bal;
 int security_code;
 static int count;
 public:
    Account(int a, int b, int c){
        account_no=a;
        account_bal=b;
        security_code=c;
        count++;
    }
    void display(){
        cout<<"Account number is: "<<account_no<<endl;
        cout<<"Account balance is: "<<account_bal<<endl;
        cout<<"Security code is: "<<security_code<<endl<<endl;
    }
    static void displaycount(void){
        cout<<"The total number of constructed objects are: "<<count<<endl;
    }
 
};
int Account::count=0;
int main(){
 Account a1(123, 1000, 1234);
    Account a2(124, 2000, 1235);
    Account a3(125, 3000, 1236);
    Account a4(126, 4000, 1237);
    Account a5(127, 5000, 1238);
    
    a1.display();
    a2.display();
    a3.display();   
    a4.display();
    a5.display();
     
 //   cout<<"the total number of constructed objects are: "<<Account::count<<endl;
 Account::displaycount();
    return 0;
}