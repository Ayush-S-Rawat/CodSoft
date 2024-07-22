//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void displayarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool swaping=false;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swaping = true;
            }
        }
        if(swaping==false)
            break;
    }
}

int main()
{
    int n,arr[10000];
        cout<<"Enter size of array: ";
        cin>>n;
        cout<<"Enter elments of array: ";
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"\nArray before Bubble Sort:\n";
        displayarray(arr,n);
        bubblesort(arr,n);
        cout<<"\nArray after Bubble Sort:\n";
        displayarray(arr,n);
    return 0;
}
