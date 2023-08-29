#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void play(int num)
{
    int guess;
    do
    {
        cin >> guess;
        if(guess == num)
        {
            cout<<"\n\nCongrats! you guessed the number correctly.\n\n";
            return;
        }
        else if(guess > num)
        {
            cout<<"\n\nThe number is smaller than your guess.\n\n";
        }
        else
        {
            cout<<"\n\nThe number is greater than your guess.\n\n";
        }
    } while(guess != num);
}

int main()
{
    int num;
    string ch;
    srand(time(0));
    do
    {
        num = rand() % 100;
        play(num);
        cout<<"\n\nWant to play again?? : (Y for yes and anything else for No)\n";
        cin>>ch;
    } while(ch=="Y");
    return 0;
}
