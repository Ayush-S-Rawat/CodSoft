//#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue<int> q;
    int topele;
    public:

    Stack() {
        topele = -1;
    }
    void push(int data) {
        topele = data;
        q.push(data);
    }
    int pop() {
        if(q.empty()) {
            return -1;
        }
        int num = topele;
        while(q.front() != num) {
            q.push(q.front());
            topele = q.front();
            q.pop();
        }
        num = q.front();
        q.pop();
        if(q.empty())
            topele = -1;
        return num;
    }
    int top() {
        return topele;
    }
    int size() {
        return q.size();
    }
};

int main()
{
    Stack s;
    cout<< s.top() << endl;
    s.push(4);
    s.push(7);
    s.push(6);
    cout<< s.top() << endl;
    cout<< s.pop() << endl;
    cout<< s.top() << endl;
    cout<< s.pop() << endl;
    cout<< s.top() << endl;
    cout<< s.pop() << endl;
    cout<< s.top() << endl;
    cout<< s.pop() << endl;
    cout<< s.top() << endl;
    s.push(2);
    cout<< s.top() << endl;
    cout<< s.pop() << endl;
    return 0;
}