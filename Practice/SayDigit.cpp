//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void digit(int n, string arr[])
{
    if(n==0)
        return;
    
    digit(n/10,arr);

    int digit=n%10;
    cout<<arr[digit]<<endl;
}

int main()
{
    int t;
        cin>>t;
        cout<<endl;
    string arr[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
        digit(t,arr);
    return 0;
}
