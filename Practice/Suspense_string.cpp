#include <bits/stdc++.h>

using namespace std;

void solve(int t)
{
    int z=t;
    while(t--)
    {
        int n,i,j,k;
        string s;
            cin>>n;
            cin>>s;
        deque<char> d;
        for(k=1,j=n-1,i=0;k<=n;k++)
        {
            if(k%2!=0)
            {
                if(s[i]=='0')
                    d.push_front('0');
                else
                    d.push_back('1');
                i++;
            }
            else
            {
                if(s[j]=='1')
                    d.push_front('1');
                else
                    d.push_back('0');
                j--;
            }
        }
        for(i=0;i<n;i++)
            cout<<d[i];
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