#include<iostream>

using namespace std;

int main()
{
    int a,b,pow=1;
        cout<<"Enter number and its power : ";
        cin>>a>>b;
        for(int i=0;i<b;i++)
        {
            pow*=a;
        }
        cout<<a<<"^"<<b<<"is "<<pow;
    return 0;
}