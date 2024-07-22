#include<iostream>

using namespace std;

int setbits(int num)
{
    int count=0;
    while(num!=0)
    {
        if(num&1)
            count++;
        num=num>>1;
    }
    return count;
}

int main()
{
    int a,b;
        cin>>a>>b;
        cout<<"Setbits in "<<a<<" is "<<setbits(a)<<endl;
        cout<<"Setbits in "<<b<<" is "<<setbits(b)<<endl;
    return 0;
}