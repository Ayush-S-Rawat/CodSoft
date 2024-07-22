#include<iostream>

using namespace std;

int n_fibo(int num)
{
    int a=0,b=1,c;
    if(num==1)
        return 0;
    else if(num==1)
        return 1;
    else{
        for(int i=1;i<=num-2;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
}

int main()
{
    int n;
        cin>>n;
        cout<<n<<"th fibonacci term is "<<n_fibo(n)<<endl;
    return 0;
}