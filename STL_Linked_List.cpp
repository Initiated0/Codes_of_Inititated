#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next = NULL;
};

void printList(Node* x)
{
    while(x!= NULL)
    {
        cout<<x->val<<" ";
        x = x->next;
    }
    cout<<endl;
}

void addNode(int val, Node* head)
{
    Node* str = new Node();
    str->val = val;

    Node* x = new Node();
    Node* prv = new Node();
    x = prv = head;

    while(x != NULL)
    {
        if(x->val > val)
            break;
        prv = x;
        x = x->next;
    }

    prv->next = str;
    str->next = x;
}

void deleteAnode(int val, Node* head)
{
    Node * x = new Node();
    Node * prv = new Node();

    x = head;
    prv = head;

    while(x != NULL)
    {
        if(x -> val == val)
            break;
        prv = x;
        x = x -> next;
    }
    prv -> next = x -> next;

}


int main()
{
    //first create node pointers then assign new nodes to those pointers
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    // this is at one step
    Node* fourth = new Node();

    head->val = 1;
    head->next = second;

    second->val = 22;
    second->next = third;

    third->val = 333;
    third->next = fourth;

    fourth->val = 4444;
    fourth->next = NULL;


    printList(head);


    addNode(5555, head);

    addNode(666666, head);
    addNode(12, head);
    addNode(123, head);

    for(Node* x = head; x != NULL; x = x->next)
    {
        printf("%d ", x->val);
    }

    cout<<endl;


    deleteAnode(12, head);
    deleteAnode(666666, head);


    for(Node* x = head; x != NULL; x = x->next)
    {
        printf("%d ", x->val);
    }


    return 0;

}
