#include<bits/stdc++.h>
using namespace std;

void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int low,int arr[],int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high;j++)
    {
        if(arr[j]<=pivot)
        {
            swap(&arr[j],&arr[i+1]);
            i++;
        }
    }
    return i;
}

void quickSort(int arr[], int low, int high)
{
    if(high>low)
    {
        int i=partition(low,arr,high);
        quickSort(arr,low,i-1);
        quickSort(arr,i+1,high);
    }
}

int main()
{
    int n=7;
        cin>>n;
    int* arr = new int[n];
    // int arr[7] = {6,3,9,5,2,8,4};
    bool check = true;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(i>0 && check)
            {
                if(arr[i]>arr[i-1])
                    check = false;
            }
        }
        if(!check)
            quickSort(arr,0,n-1);
        else
            for(int i=0;i<=n/2;i++)
                swap(&arr[i],&arr[n-i-1]);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        delete arr;
    return 0;
}