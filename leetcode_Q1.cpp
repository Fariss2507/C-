# include<iostream>
using namespace std;

class Solution {
    public:
        int subtractProductAndSum(int n){
    int rem,prod=1,sum=0;
           while(n!=0)
           {
            rem=n%10;
            prod=prod*rem;
            sum=sum+rem;
            n=n/10;
           }
        return prod-sum;
    }
    };

    int main(){

        Solution f1;
        f1.subtractProductAndSum(4421);
        return 0;
    }