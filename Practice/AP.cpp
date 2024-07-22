#include<iostream>

using namespace std;

int ap(int num)
{
    return (3*num+7);
}

int main()
{
    int n;
        cin>>n;
        cout<<n<<"th term of A.P. (3*n+7) is "<<ap()<<endl;
    return 0;
}