//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int bsearch(int arr[], int n, int k)
{
    if(n<=0)
        return -1;
    if(arr[n/2]==k)
        return n/2;
    else if(arr[n/2]>k)
        return bsearch(arr,n/2,k);
    else
    {
        int x=bsearch(&arr[n/2+1],n-n/2-1,k);
            if(x==-1)
                return -1;
            else
                return x+(n/2)+1;
    }
}

int main()
{
    int arr[]={2,5,8,13,18,24};
        // cin>>t;
        cout<<bsearch(arr,6,8);
    return 0;
}
