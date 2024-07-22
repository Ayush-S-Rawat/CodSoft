//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int sumarray(int arr[], int n)
{
    if(n==0)
        return 0;
    return arr[0]+sumarray(arr+1,n-1);
}

int main()
{
    int arr[5]={3,4,5,1,6};
        // cin>>t;
        cout<<sumarray(arr,5)<<endl;
    return 0;
}
