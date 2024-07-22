#include<iostream>

using namespace std;

int main()
{
    int num,sq_rt;
        cin>>num;
        for(int i=0;i<num;i++)
        {
            if(num==i*i)
            {
                sq_rt=i;
                break;
            }
            if(num<i*i)
            {
                sq_rt=i-1;
                break;
            }
        }
        cout<<"Square root is "<<sq_rt;
    return 0;
}