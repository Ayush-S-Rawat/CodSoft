#include<iostream>

using namespace std;

int main()
{
    int arr[100],i,n;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>arr[i];
        for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
        for(i=1;i<n;i+=2)
        {
            int x=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=x;
        }
        cout<<endl;
        for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
    return 0;
}