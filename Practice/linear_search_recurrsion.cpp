//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int linearsearch(int arr[],int n,int key)
{
    if(n==0)
        return false;
    
    if(arr[0]==key)
        return true;

    return linearsearch(arr+1,n-1,key);
}

int main()
{
    int arr[7]={1,2,3,4,5,6,7};
    bool t=linearsearch(arr,7,5);
        // cin>>t;
        if(t)
            cout<<"Element present";
        else
            cout<<"Element not present";
    return 0;
}
