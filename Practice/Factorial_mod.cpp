//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int solve(int t)
{
    if(t==2)
        return 2;
    int m=1e9 + 7;

    long long ans = ( (solve(t-1)%m) * t ) % m;

    return ans;
    
}

int main()
{
    int t;
        cin>>t;
        cout<< solve(t) <<endl;
    return 0;
}
