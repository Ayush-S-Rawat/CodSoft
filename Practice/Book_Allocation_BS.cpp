#include <iostream>

using namespace std;

bool possiblesol(int arr[], int mid, int n, int m)
{
    int partitions = 0, sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>mid)
        {
            partitions++;
            sum=0;
            i--;
        }
    }
    if(partitions == m-1)
        return true;
    else
        return false;
}

int minchapterallocation(int arr[], int n, int m)
{
    int sum = 0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
    int s=0, e=sum;
    int mid = s+(e-s)/2;
    int ans = -1;
        while(s<e)
        {
            if(possiblesol(arr,mid,n,m))
            {
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
            mid = s+(e-s)/2;
        }
    return ans;
}

int main()
{
    int arr[] = {30,20,10,40,5,45};
    int chapters = 6;
    int days = 3;
    cout<<minchapterallocation(arr,chapters,days)<<endl;
    return 0;
}