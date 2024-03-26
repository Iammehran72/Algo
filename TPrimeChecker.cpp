#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)	
    {
        return false;
    }
    for(int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isTPrime(int num) 
{
    int sqrtNum = sqrt(num);
    return isPrime(sqrtNum) && (sqrtNum * sqrtNum == num);
}

int main()
{
    int num[] = {4, 9, 10, 16, 25};
    int n = sizeof(num) / sizeof(num[0]);
    
    for(int i = 0; i < n; i++)
    {
        if (isTPrime(num[i]))
        {
            cout << "The Number " << num[i] << " is T-prime." << endl;
        }
        else
        {
            cout << "The Number " << num[i] << " is not T-prime." << endl;
        }
    }
    return 0;
}
