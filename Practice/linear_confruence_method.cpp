#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    fstream file;
        file.open("new_file.txt",ios::out);

        if(!file)
        {
            cout<<"File creation failed."<<endl;
        }
        else
        {
            file.trunc;
            int i=5,x=7,m=8,a=29,c=97,num;
            file<<x;
            cout<<x<<" ";
            i--;
            while(i--)
            {
                num=((x*a)+c)%m;
                cout<<num<<" ";
                file<<num;
                x=num;
            }
            file.close();
        }
}