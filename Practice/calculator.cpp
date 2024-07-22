#include<iostream>

using namespace std;

int main()
{
    int a,b;
    char ch;
        cout<<"Enter two number say A and B: ";
        cin>>a>>b;
        cout<<"Enter operator: ";
        cin>>ch;
        switch(ch){
            case '+':
                cout<<"A+B = "<<a+b;
                break;
            case '-':
                cout<<"A-B = "<<a-b;
                break;
            case '*':
                cout<<"A*B = "<<a*b;
                break;
            case '/':
                cout<<"A/B = "<<a/b;
                break;
            case '%':
                cout<<"A%B = "<<a%b;
                break;
        }
    return 0;
}