//#include <bits/stdc++.h>
#include <iostream>
#include <math.h>

using namespace std;

void solve(int t)
{
    int z=t;
    while(t--)
    {
        float a,b,c;
            cin>>a>>b>>c;
        double r1=((-b)+sqrt(b*b - 4*a*c))/2*a;
        double r2=((-b)-sqrt(b*b - 4*a*c))/2*a;
            cout<<"Roots are: "<<r1<<" "<<r2<<endl;;
    }
}

int main()
{
    int t;
        // cin>>t;
        solve(1);
    return 0;
}
