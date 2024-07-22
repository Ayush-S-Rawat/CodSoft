#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
}

int main()
{
    int a=5,b=8;

    cout<<"Before Swap:\na = "<<a<<"\nb = "<<b<<"\n\n";

    swap(a,b);

    cout<<"After Swap:\na = "<<a<<"\nb = "<<b<<"\n\n";
}