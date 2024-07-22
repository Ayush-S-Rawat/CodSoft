#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node()
        {
            this->data = 0;
            this->next = NULL;
        }
        Node(int x)
        {
            this->data = x;
            this->next = NULL;
        }
        Node(int x, Node* next)
        {
            this->data = x;
            this->next = next;
        }
};

pair<Node*, Node*> CLL_to_2CLL(Node* head)
{
    pair<Node*, Node*> ans;

    if(head == NULL)
        return {NULL, NULL};
    if(head->next == head)
    {
        return {head, NULL};
    }
    Node* fast = head->next;
    Node* slow = head;

    while(fast != head)
    {
        fast = fast->next;
        if(fast != head)
            fast = fast->next;
        slow = slow->next;
    }
    fast->next = slow->next;
    ans.second = slow->next;
    slow->next = head;
    ans.first = head;

    return ans;
}

void print(Node* head)
{
    if(head == NULL)
    {
        cout<<"\n\nEmpty List\n\n";
        return ;
    }

    Node* temp = head;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while(temp != head);
}

int main()
{
    Node* head = new Node(1);
    Node* tail = head->next;
    tail = new Node(2);
    tail = tail->next;
    tail = new Node(3);
    tail = tail->next;
    tail = new Node(4);
    tail = tail->next;
    // Making it circular
    tail->next = head;

    print(head);

    pair<Node*, Node*> ans;
    ans = CLL_to_2CLL(head);

    print(ans.first);
    cout<<"\n\n";
    print(ans.second);
}