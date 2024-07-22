#include <iostream>
using namespace std;

int main()
{
    long long int n,m,i,maxi=-1,x,ans=0;
        cin>>n>>m;
    long long int v[n];
        for(i=0;i<n;i++)
        {
            cin>>v[i];
            maxi=max(maxi,v[i]);
        }
    long long int s=0,e=maxi;
    long long int mid=s+(e-s)/2;
    bool check;
        while(s<=e)
        {
            x=m;
            check=false;
            for(i=0;i<n;i++)
            {
                if(v[i]>mid)
                {
                    x-=(v[i]-mid);
                }
                if(x<=0)
                {
                    ans=mid;
                    s=mid+1;
                    check=true;
                }
            }
            if(!check)
            {
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        cout<<ans<<endl;
}