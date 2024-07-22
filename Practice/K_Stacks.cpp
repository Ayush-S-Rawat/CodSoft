#include <bits/stdc++.h>
// #include <iostream>

using namespace std;

class KStack {
    private:
        int* arr;
        int freespot;
        int* next;
        int* top;
    public:
        KStack(int size, int K) {
            freespot = 0;
            arr = new int[size];
            next = new int[size];
            top = new int[K];

            for(int i=0;i<size;i++) {
                next[i] = i+1;
            }
            next[size-1] = -1;

            for(int i=0;i<K;i++) {
                top[i] = -1;
            }
        }

        bool push(int x, int m) {
            if(freespot == -1) {
                return false;
            }
            int index = freespot;
            freespot = next[index];
            next[index] = top[m-1];
            arr[index] = x;
            top[m-1] = index;
            return true;
        }

        int pop(int m) {
            if(top[m-1] == -1)
                return -1;
            int index = top[m-1];
            top[m-1] = next[index];
            next[index] = freespot;
            freespot = index;
            return arr[index];
        }

        int tos(int m) {
            return arr[top[m-1]];
        }
};

int main()
{
    KStack stk(6,3);
    cout << stk.pop(2) << endl;
    cout << stk.push(8,2) << endl;
    cout << stk.push(1,2) << endl;
    cout << stk.push(25,2) << endl;
    cout << stk.push(41,3) << endl;
    cout << stk.push(20,2) << endl;
    cout << stk.push(17,2) << endl;
    cout << stk.pop(2) << endl;
    cout << stk.pop(2) << endl;
    cout << stk.pop(2) << endl;
    cout << stk.push(12,2) << endl;
    return 0;
}
