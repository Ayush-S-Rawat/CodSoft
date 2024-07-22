#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
        cin>>n;
        cout<<"Decimal number is "<<n;
        vector<int> s;
        while(n!=0)
        {
            s.push_back(n%2);
            n/=2;
        }
        cout<<"\n\nBinary number is ";
        for(int i=s.size()-1;i>=0;i--)
        {
            cout<<s[i];
        }
    return 0;
}