#include<iostream>

using namespace std;

int main()
{
    int n,max=INT32_MIN,min=INT32_MAX;
        cin>>n;
    int arr[1000]={0};
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>max)
                max=arr[i];
            if(arr[i]<min)
                min=arr[i];
        }
        cout<<"Maximun element is "<<max<<endl;
        cout<<"Minimum element is "<<min<<endl;
    return 0;
}