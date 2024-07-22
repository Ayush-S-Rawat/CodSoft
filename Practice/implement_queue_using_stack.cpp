//#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

class Queue {
    stack<int> s;
    int frontele;
    public:

    Queue() {
        frontele = -1;
    }
    void enqueue(int data) {
        if(s.empty()) {
            frontele = data;
            s.push(data);
        }
        else {
            s.push(data);
        }
    }
    int dequeue() {
        if(s.empty())
            return -1;
        int num, n = s.size();
        int* temp = new int[n];
        int i = 0;
        while(!s.empty()) {
            temp[i++] = s.top();
            s.pop();
        }
        for(int i=n-2;i>=0;i--) {
            s.push(temp[i]);
        }
        num = temp[n-1];
        if(n>1)
            frontele = temp[n-2];
        else
            frontele = -1;
        delete[] temp;
        return num;
    }
    int front() {
            return frontele;
    }
    int size() {
        return s.size();
    }
};

int main()
{
    Queue q;
    cout<< q.front() << endl;
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(6);
    cout<< q.front() << endl;
    cout<< q.dequeue() << endl;
    cout<< q.front() << endl;
    cout<< q.dequeue() << endl;
    cout<< q.front() << endl;
    cout<< q.dequeue() << endl;
    cout<< q.front() << endl;
    cout<< q.dequeue() << endl;
    cout<< q.front() << endl;
    q.enqueue(2);
    cout<< q.front() << endl;
    cout<< q.dequeue() << endl;
    return 0;
}