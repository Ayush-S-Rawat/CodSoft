#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void seive(int n)
{
    int size=floor(sqrt(n));

    int low=2;
    int high=size-1;

    vector<int> prime;

    while(low<n)
    {
        if(high>=n)
            high=n;
        
        vector<int> arr(high-low+1,1);

        for(int i=0;i<prime.size();i++)
        {
            for(int j=2*prime[i];j<=high;j+=prime[i])
            {
                arr[j%size]=0;
            }
        }

        for(int i=low;i<=high;i++)
        {
            if(arr[i%size])
            {
                prime.push_back(i);
            }
        }

        low=high+1;
        high=low+size-1;
    }

    if(prime.size()==0)
    {
        cout<<"No prime number present"<<endl;
    }
    else
    {
        cout<<"Prime numbers less than n:"<<endl;
        for(int i=0;i<prime.size();i++)
        {
            cout<<prime[i]<<" ";
        }
    }
}

int main()
{
    int t;
        cin>>t;
        seive(t);
    return 0;
}