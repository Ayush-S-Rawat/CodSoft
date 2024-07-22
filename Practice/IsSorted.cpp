//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool issorted(int arr[], int n)
{
    if(n==1 || n==0)
        return true;
    
    if(arr[0]<=arr[1])
        return issorted(&arr[1],n-1);
    
    return false;
}

int main()
{
    int arr[10]={3,6,8,12,4,76,81,87,92,100};
        // cin>>t;
        if(issorted(arr,10))
            cout<<"Array is sorted.";
        else
            cout<<"Array is not sorted.";
    return 0;
}
