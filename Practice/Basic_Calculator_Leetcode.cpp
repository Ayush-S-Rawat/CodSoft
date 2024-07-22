#include <bits/stdc++.h>

using namespace std;

bool checkdigit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}
long evaluate(string &s, int &i)
{
    stack<long> operand;
    stack<char> operators;
    stack<char> bracket;
    long num, a, b;
    string temp;
    bracket.push('(');
    i++;
    while (!bracket.empty() && i < s.length())
    {
        if (checkdigit(s[i]))
        {
            while (checkdigit(s[i]))
            {
                temp.push_back(s[i]);
                i++;
            }
            i--;
            operand.push(stoi(temp));
            temp.clear();
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            if (operators.size() == 0)
            {
                operators.push(s[i]);
            }
            else
            {
                if (operand.size() == 1)
                {
                    if (operators.top() == '-')
                    {
                        num = operand.top();
                        num = num * (-1);
                        operand.pop();
                        operand.push(num);
                    }
                }
                else
                {
                    b = operand.top();
                    operand.pop();
                    a = operand.top();
                    operand.pop();

                    if (operators.top() == '+')
                        operand.push(a + b);
                    else
                        operand.push(a - b);
                    operators.pop();
                }
            }
            operators.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (operators.size() != 0)
            {
                if (operand.size() == 1)
                {
                    if (operators.top() == '-')
                    {
                        num = operand.top();
                        num = num * (-1);
                        operand.pop();
                        operand.push(num);
                    }
                }
                else
                {
                    b = operand.top();
                    operand.pop();
                    a = operand.top();
                    operand.pop();

                    if (operators.top() == '+')
                        operand.push(a + b);
                    else
                        operand.push(a - b);
                    operators.pop();
                }
            }
            bracket.pop();
        }
        else
        {
            num = evaluate(s, i);
            if (!operators.empty() && num < 0 && operators.top() == '-')
            {
                operand.push(num * (-1));
                operators.pop();
                operators.push('+');
            }
            else
            {
                operand.push(num);
            }
            i--;
        }
        i++;
    }
    return operand.top();
}
int calculate(string s)
{
    // Removing space
    string exp;
    exp.push_back('(');
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
            exp.push_back(s[i]);
    }
    exp.push_back(')');
    int i = 0;
    return evaluate(exp, i);
}

int main()
{
    string s = "1 + 1";
    cout << calculate(s) << endl;
    return 0;
}