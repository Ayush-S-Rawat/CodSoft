#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string s,word;
    int count = 0;

    cout<<"Enter name of the file: ";
    cin>>s;

    ifstream file(s);
    if(file)
    {
        while(!file.eof())
        {
            file >> word;
            count++;
        }
    }
    else
    {
        cout<<"\n\nFile does not exist.\n\n";
    }

    cout<<"Total words in the file are : "<<count;

    file.close();
 
    return 0;
}