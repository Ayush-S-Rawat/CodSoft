#include<iostream>

using namespace std;

int main()
{
    char ch;
        cin>>ch;
        if(ch>=97 && ch<=122)
        {
            cout<<"Lowercase"<<endl;
        }
        else if(ch>=48 && ch<=57)
        {
            cout<<"Number"<<endl;
        }
        else if(ch>=65 && ch<=90)
        {
            cout<<"Uppercase"<<endl;
        }
    return 0;
}