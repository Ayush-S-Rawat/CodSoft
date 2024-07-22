#include <bits/stdc++.h>

using namespace std;

long long int binary2int(string s,long n)
{
    long long int num=0;
    for(long i=0;i<n;i++)
    {
        if(s[i]=='1')
            num+=pow(2,n-1-i);
    }
    return num;
}

long maximum(long long int x,long n)
{
    long ans=0;
    long long int a=-1,k,b,j;
        for(long i=1;i<=n;i++)
        {
            j=pow(2,i);
            k=x/j;
            b=x^k;
            if(b >= a)
            {
                ans=i;
                a=b;
                // cout<<endl<<a<<" "<<ans<<" "<<endl;
            }
            if(k==0)
                break;
        }
    return ans;
}

void solve(int t)
{
    int z=t;
    while(t--)
    {
        long n;
        string s;
            cin>>n>>s;
        long long int num=binary2int(s,n);
            // cout<<num;
            cout<<maximum(num,n);
        cout<<endl;
    }
}
int main()
{
    int t;
        cin>>t;
        solve(t);
    return 0;
}