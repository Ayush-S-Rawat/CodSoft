#include<iostream>

using namespace std;

int main()
{
    int arr[1000]={0},n,sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        cout<<"Sum of array is "<<sum;
    return 0;
}