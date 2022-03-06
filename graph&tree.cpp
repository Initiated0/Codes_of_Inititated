#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int val;
    Node* parent = NULL;
    Node* leftchild = NULL;
    Node* rightchild = NULL;
};

Node* createLchild(Node* parent, int val)
{
    Node* a = new Node();
    a-> val = val;
    a->parent = parent;
    parent->leftchild = a;
    return a;
}

Node* createRchild(Node* parent, int val)
{
    Node* a = new Node();
    a-> val = val;
    a->parent = parent;
    parent->rightchild = a;
    return a;
}

void printTree(Node * curr)
{
    if(curr->leftchild == NULL || curr->rightchild == NULL)
    {
        cout<<curr->val<<endl;
        return;
    }

    printTree(curr->leftchild);
    printTree(curr->rightchild);

}

void printTree2(Node * curr)
{
    if(curr->leftchild == NULL || curr->rightchild == NULL)
    {
        cout<<curr->val<<endl;
        return;
    }

    cout<<curr->val<<endl;

    printTree(curr->leftchild);
    printTree(curr->rightchild);

}


int main()
{
    Node* head = new Node();
    head->val = 10;

    Node* lchild = createLchild(head, 5);
    Node* rchild = createRchild(head, 15);

    Node* lchild2 = createLchild(lchild, 1);
    Node* rchild2 = createRchild(lchild, 9);


    Node* lchild3 = createLchild(rchild, 11);
    Node* rchild3 = createRchild(rchild, 20);

    printTree(head);
    cout<<"****************************************"<<endl;
    printTree2(head);
    cout<<endl;
    cout<<"     "<<head->val<<endl;
    cout<<"  "<<head->leftchild->val<<"      "<<head->rightchild->val<<endl;
    cout<<head->leftchild->leftchild->val<<"  "<<head->leftchild->rightchild->val<<"   "<<head->rightchild->leftchild->val<<"  "<<head->rightchild->rightchild->val<<endl;

    return 0;
}
