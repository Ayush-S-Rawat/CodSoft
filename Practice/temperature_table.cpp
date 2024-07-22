#include<iostream>

using namespace std;

int main()
{
    double f,c;
    char t;
    cout<<"Enter temperature in farenheight or celcius"<<endl<<"(Enter 'f' for farenheight and 'c' for celciius): ";
    cin>>t;

    if(t=='c')
    {
        cout<<"Enter temperature in celcius : ";
        cin>>c;
        f=(c* (9/5.0))+32;
        cout<<"temperature in Farenheight is : "<<f<<endl;
    }
    else if(t=='f')
    {
        cout<<"Enter temperature in farenheight : ";
        cin>>f;
        c=(f-32)* (5.0/9);
        cout<<"temperature in celcius is : "<<c<<endl;
    }
    else{
        cout<<"Read instructions carefully.";
    }
    return 0;
}