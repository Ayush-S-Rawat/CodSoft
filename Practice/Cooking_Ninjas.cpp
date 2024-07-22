#include <bits/stdc++.h> 

bool ispossible(vector<int> &rank, int m, int mid)
{
    int time=0,x=0;
    for(int i=0;i<rank.size();i++)
    {
        time=rank[i];
        for(int j=2;time<=mid;j++)
        {
            time=time+(rank[i]*j);
            x++;
            if(x==m)
                return true;
        }
        time=0;
    }
    return false;
}

int minCookTime(vector<int> &rank, int m)
{
    int s=0,e=10000000,ans=0;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
        if(ispossible(rank,m,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}