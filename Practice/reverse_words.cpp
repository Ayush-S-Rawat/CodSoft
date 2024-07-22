//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    char s[100];
    int i,j,c,d;
        gets(s);
        cout<<"String before reverse: "<<s<<endl;
        for(i=0;s[i]!='\0';i++);
    int n=i;
        for(i=0,j=0;i<n;j++)
        {
            if(s[j]==' ' || s[j]=='\0')
            {
                for(c=i,d=j-1;c<=d;c++,d--)
                {
                    swap(s[c],s[d]);
                }
                i=j+1;
            }
        }
        cout<<"String after reverse: "<<s<<endl;
    return 0;
}