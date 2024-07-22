#include<iostream>

using namespace std;

bool isprime(int num)
{
    for(int i=2;i<=num/2;i++)
    {
        if(num%i==0)
            return false;
    }
    return true;
}

int main()
{
    int n;
        cin>>n;
        if(isprime(n))
            cout<<"The number "<<n<<" is prime number"<<endl;
        else   
            cout<<"The number "<<n<<" is not a prime number"<<endl;   
    return 0;
}