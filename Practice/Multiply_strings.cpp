#include<iostream>
#include<string.h>
using namespace std;
    string multiply(string num1, string num2) {
        string temp,prev,sum;
        int n=num1.length(),m=num2.length(),carry,num;
        int i,j,k,l;
        char x;
        for(i=m-1;i>=0;i--)
        {
            carry=0;
            for(j=n-1;j>=0;j--)
            {
                num=(num2[i]-48)*(num1[j]-48);
                temp.push_back(((num+carry)%10)+48);
                carry=(num+carry)/10;
            }
            // reverse of temp
            for(k=0,l=temp.length()-1;k<l;k++,l--)
            {
                x=temp[k];
                temp[k]=temp[l];
                temp[l]=x;
            }
            for(k=i;k<m-1;k++)
            {
                temp.push_back('0');
            }
            k=temp.length()-1;
            l=prev.length()-1;
            carry=0;
            // adding temp and prev
            while(k>=0 && l>=0)
            {
                num = (temp[k]-48) + (prev[l]-48) + carry;
                sum.push_back((num%10)+48);
                carry=num/10;
            }
            while(k>=0)
            {
                num = (temp[k]-48) + carry;
                sum.push_back((num%10)+48);
                carry=num/10;
            }
            while(l>=0)
            {
                num = (prev[l]-48) + carry;
                sum.push_back((num%10)+48);
                carry=num/10;
            }
            if(carry)
            {
                sum.push_back(carry+48);
            }
            for(k=0,l=sum.length()-1;k<l;k++,l--)
            {
                x=sum[k];
                sum[k]=sum[l];
                sum[l]=x;
            }
            prev=sum;
        }
        return sum;
    }

int main()
{
    string num1="9",num2="9";
    // cout<<multiply(string1,string2)<<endl;
    string temp,prev,sum;
        int n=num1.length(),m=num2.length(),carry,num;
        int i,j,k,l;
        char x;
        for(i=m-1;i>=0;i--)
        {
            carry=0;
            for(j=n-1;j>=0;j--)
            {
                num=(num2[i]-48)*(num1[j]-48);
                temp.push_back(((num+carry)%10)+48);
                carry=(num+carry)/10;
            }
            if(carry)
            {
                temp.push_back(carry+48);
            }
            // reverse of temp
            for(k=0,l=temp.length()-1;k<l;k++,l--)
            {
                x=temp[k];
                temp[k]=temp[l];
                temp[l]=x;
            }
            for(k=i;k<m-1;k++)
            {
                temp.push_back('0');
            }
            k=temp.length()-1;
            l=prev.length()-1;
            carry=0;
            // adding temp and prev
            while(k>=0 && l>=0)
            {
                num = (temp[k]-48) + (prev[l]-48) + carry;
                sum.push_back((num%10)+48);
                carry=num/10;
                k--;
                l--;
            }
            while(k>=0)
            {
                num = (temp[k]-48) + carry;
                sum.push_back((num%10)+48);
                carry=num/10;
                k--;
            }
            while(l>=0)
            {
                num = (prev[l]-48) + carry;
                sum.push_back((num%10)+48);
                carry=num/10;
                l--;
            }
            if(carry)
            {
                sum.push_back(carry+48);
            }
            for(k=0,l=sum.length()-1;k<l;k++,l--)
            {
                x=sum[k];
                sum[k]=sum[l];
                sum[l]=x;
            }
            prev=sum;
            sum.clear();
            temp.clear();
        }
        cout<<prev;
    return 0;
}