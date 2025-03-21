#include <iostream>
#include <cmath>

using namespace std;

bool Armstrong(int number)
{
    int originalNumber = number, sum = 0, numDigits = 0;

    int temp = number;
    while (temp > 0)
    {
        temp /= 10;
        numDigits++;
    }

    temp = number;
    while (temp > 0)
    {
        int digit = temp % 10;
        sum += pow(digit, numDigits);
        temp /= 10;
    }

    return sum == originalNumber;
}

int main()
{
    int num;
    cout << "Enter nunm" << endl;
    cin >> num;

    if (Armstrong(num))
    {
        cout << num << " Amstrong hy" << endl;
    }
    else
    {
        cout << num << " Armstrong nh hy " << endl;
    }

    return 0;
}
