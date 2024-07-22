//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int findpivot(int arr[], int s, int e)
{
    if(e<=s)
        return s;
    int mid=s+(e-s)/2;
    
    if(arr[mid]>=arr[0])
        return findpivot(arr,mid+1,e);
    else
        return findpivot(arr,s,mid);
}

int main()
{
    int arr[]={8,4};
        // cin>>t;
        cout<<findpivot(arr,0,1);
    return 0;
}
