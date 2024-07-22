#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,i;
        cout<<"Enter negative number ";
        cin>>n;
    vector<int> v(32);
        for(i=32;i>=1;i--)
        {
            v[i]=(n%2)/(-1);
            n/=2;
        }
        // 1's compliment
        for(i=0;i<=32;i++)
        {
            if(v[i]==0)
                v[i]=1;
            else
                v[i]=0;
        }
        for(i=32;i>=1;i--)
        {
            if(v[i]==0)
            {
                v[i]=1;
                break;
            }
            else
                v[i]=0;
        }
        // 2's compliment
        for(i=1;i<=32;i++)
        {
            if(v[i]==0)
                v[i]=1;
            else
                v[i]=0;
        }
        for(i=32;i>=1;i--)
        {
            if(v[i]==0)
            {
                v[i]=1;
                break;
            }
            else
                v[i]=0;
        }
        cout<<"Binary of "<<n<<"is ";
        for(i=0;i<=32;i++)
            cout<<v[i];
    return 0;
}