#include <iostream>

using namespace std;

class Node {
    public:

    int data;
    Node* left;
    Node* right;
    
    Node(int ele) {
        this->data = ele;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* find_pre(Node* root) {
    Node* temp = root;
    temp = temp->left;
    while(temp->right != NULL && temp->right != root) {
        temp = temp->right;
    }
    return temp;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(11);
    root->right->left = new Node(17);
    root->right->right = new Node(18);

    // Morris Traversal

    Node* pred = NULL;
    Node* cur = root;
    while(cur != NULL) {
        if(cur->left != NULL) {
            pred = find_pre(cur);

            if(pred->right == NULL) {
                pred->right = cur;
                cur = cur->left;
            }
            else {
                pred->right = NULL;
                cout << cur->data << "  ";
                cur = cur->right;
            }
        }
        else {
            cout << cur->data << "  ";
            cur = cur->right;
        }
    }

    return 0;
}