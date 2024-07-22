#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node() {
            data = 0;
            left = NULL;
            right = NULL;
        }
        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};

void reverseBFS(Node* root) {
    queue<Node*> q;
    stack<Node*> s;
    Node* temp;
    q.push(root);
    q.push(NULL);
    s.push(NULL);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        s.push(temp);
        if(temp) {
            cout << temp->data << "   ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        else {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
    }
    cout<<"\n\n";
    stack<Node*> stk;
    while(!s.empty()) {
        temp = s.top();
        s.pop();
        if(temp) {
            stk.push(temp);
        }
        else {
            while(!stk.empty()) {
                temp = stk.top();
                cout<<temp->data << "  ";
                stk.pop();
            }
            cout<<endl;
        }
    }
}

Node* maketree(Node* root) {
    int data;
    cout<<"Enter data: ";
    cin >> data;
    if(data == -1)
        return NULL;
    root = new Node(data);
    cout << "Going left. ";
    root->left = maketree(root->left);
    cout<<"Going right. ";
    root->right = maketree(root->right);
    return root;
}

int main() {
    Node* root = NULL;
    root = maketree(root);
    reverseBFS(root);
    return 0;
}