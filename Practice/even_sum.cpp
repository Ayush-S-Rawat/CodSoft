#include<iostream>
using namespace std;

int main()
{
    int n,i=0,sum=0;
    cin>>n;

    while(i<=n)
    {
        sum+=i;
        i+=2;
    }

    cout<<"Sum of even numbers till N is : "<<sum<<endl;
    return 0;
}