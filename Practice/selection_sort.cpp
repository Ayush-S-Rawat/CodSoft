#include<iostream>

using namespace std;

//Used for small data size and if there is less space avaibility

void Selection_Sort(int arr[],int n)
{
    int i,j,mini;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1,mini=i;j<n;j++)
        {
            if(arr[j]<arr[mini])
            {
                mini=j;
            }
        }
        int temp=arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
    }
}

int main()
{
    int n,arr[100],i;
        cout<<"Enter Size of Array: ";
        cin>>n;
        cout<<"Enter elements of Array: ";
        for(i=0;i<n;i++)
            cin>>arr[i];
        Selection_Sort(arr,n);
        cout<<"Array after Selection Sort in ascending order is:\n";
        for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
}