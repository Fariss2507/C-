# include<iostream>
using namespace std;

class Solution {
    public:
        bool isUgly(int n) {
            while(n>0 || n==1){
    
                if(n%2==0 && n%3==0 && n%5==0){
                    return true;
                    cout<<"number is ugly"<<endl;
                }
            }
            return false;
            
        }

      //  void display(void){

        //    cout<<"The number"
      //  }
    };

    int main(){

        Solution a1;
        a1.isUgly(6);
        return 0;
    }