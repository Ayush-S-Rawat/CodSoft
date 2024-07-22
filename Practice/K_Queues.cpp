#include <bits/stdc++.h>
// #include <iostream>

using namespace std;

class KQueue {
    private:
        int* arr;
        int* front;
        int* rear;
        int* next;
        int freespot;
    public:
        KQueue(int size, int K) {
            arr = new int[size];
            next = new int[size];
            front = new int[K];
            rear = new int[K];
            freespot = 0;

            for(int i=0;i<K;i++) {
                front[i] = -1;
                rear[i] = -1;
            }
            for(int i=0;i<size;i++) {
                next[i] = i+1;
            }
            next[size-1] = -1;
        }
        
        bool push(int x, int m) {
            if(freespot == -1)
                return false;
            int index = freespot;
            freespot = next[index];
            if(rear[m-1] == -1)
                front[m-1] = index;
            else
                next[rear[m-1]] = index;
            rear[m-1] = index;
            next[index] = -1;
            arr[index] = x;
            return true;
        }

        int pop(int m) {
            if(front[m-1] == -1)
                return -1;
            int index = front[m-1];
            front[m-1] = next[index];
            if(next[index] == -1)
                rear[m-1] = -1;
            next[index] = freespot;
            freespot = index;
            return arr[index];
        }

        int queuefront(int m) {
            if(front[m-1] == -1)
                return -1;
            return arr[front[m-1]];
        }
};

int main()
{
    KQueue que(6,3);
    cout << que.pop(2) << endl;
    cout << que.push(8,1) << endl;
    cout << que.push(123,2) << endl;
    cout << que.push(25,2) << endl;
    cout << que.push(41,3) << endl;
    cout << que.push(20,2) << endl;
    cout << que.push(17,2) << endl;
    cout << que.pop(2) << endl;
    cout << que.pop(2) << endl;
    cout << que.pop(2) << endl;
    cout << que.push(12,2) << endl;
    return 0;
}
