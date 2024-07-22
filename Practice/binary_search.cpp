#include<iostream>

using namespace std;

int binarysearch(int arr[],int n,int k)
{
    int start=0,end=n-1;

    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(arr[mid]==k)
            return mid;
        else if(arr[mid]>k)
            end=mid-1;
        else
            start=mid+1;
    }
    return -1;
}

int main()
{
    int arr[10]={2,5,8,16,23,39,42,47,55,60};
    int index=binarysearch(arr,10,55);
    if(index!=-1)
        cout<<"55 is at index "<<index<<endl;
    else
        cout<<"55 not present."<<endl;
    return 0;
}