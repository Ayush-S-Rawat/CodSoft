//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void InsertionSort(int* arr, int start, int n)
{
    if(start==n)
        return;
    int i=start;
    while((arr[i] < arr[i-1]) && i>=1)
    {
        swap(arr[i],arr[i-1]);
        i--;
    }
    InsertionSort(arr,start+1,n);
}

int main()
{
    int arr[5] = {2,5,1,8,3};
        InsertionSort(arr,1,5);
        for(int i=0;i<5;i++)
            cout<<arr[i]<<"  ";
    return 0;
}
