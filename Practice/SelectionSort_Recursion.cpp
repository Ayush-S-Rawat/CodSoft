//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void SelectionSort(int* arr, int start, int n)
{
    if(start==n-1 || start==n)
        return;
    int i=start;
    int mini = start;
    while(i<n)
    {
        if(arr[mini] > arr[i])
            mini = i;
        i++;
    }
    swap(arr[start],arr[mini]);
    SelectionSort(arr,start+1,n);
}

int main()
{
    int arr[5] = {2,5,1,8,3};
        SelectionSort(arr,0,5);
        for(int i=0;i<5;i++)
            cout<<arr[i]<<"  ";
    return 0;
}
