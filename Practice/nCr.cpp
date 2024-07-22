#include<iostream>

using namespace std;

int fact(int num)
{
    if(num==2)
        return 2;
    return num*fact(num-1);
}

int main()
{
    int n,r;
        cout<<"Enter value of n and r: ";
        cin>>n>>r;
        cout<<"nCr is "<<fact(n)/(fact(r)*fact(n-r))<<endl;
    return 0;
}