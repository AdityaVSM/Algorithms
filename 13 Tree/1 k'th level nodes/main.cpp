#include<bits/stdc++.h>
#include "../BinaryTree.h"

using namespace std;
//Print all nodes at k'th level

void print(Node* head, int k){
    if(head==NULL)
        return;
    if(k==0)
        cout<<head->data<<" ";
    print(head->left, k-1);
    print(head->right, k-1);
}

int main(){
    BinaryTree tree;
    Node* head = NULL;
    head = tree.InsertNode(head,10);
    head = tree.InsertNode(head,20);
    head = tree.InsertNode(head,30);
    head = tree.InsertNode(head,40);
    print(head,1);
    return 0;
}