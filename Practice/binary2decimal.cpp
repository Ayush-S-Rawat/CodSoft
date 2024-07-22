#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    string s;
        cin>>s;
        cout<<"Binary numver is "<<s;
    int n=s.size(),num=0;
        for(int i=0;n>0;n--,i++)
        {
            if(s[n-1]=='1')
                num+=pow(2,i);
        }
        cout<<"\n\nDecimal number is "<<num;
    return 0;
}