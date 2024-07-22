//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = s,count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[pivot] >= arr[i])
            count++;
    }
    swap(arr[pivot],arr[s+count]);
    pivot = s+count;
    for(int i=s,j=e;i!=pivot && j!=pivot;)
    {
        while(arr[i] <= arr[pivot])
        {
            i++;
        }
        while(arr[j] > arr[pivot])
        {
            j--;
        }
        if(i!=pivot && j!=pivot)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivot;
}

void QuickSort(int arr[], int s, int e)
{
    if(s>=e)
        return;
    int pivot = partition(arr,s,e);
    QuickSort(arr,s,pivot-1);
    QuickSort(arr,pivot+1,e);
}

int main()
{
    int arr[] = {3,5,1,8,2};
        QuickSort(arr,0,4);
        for(int i=0;i<5;i++)
            cout<< arr[i] <<" ";
    return 0;
}
