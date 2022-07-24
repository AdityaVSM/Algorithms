#include<bits/stdc++.h>
#include "../BinaryTree.h"
//Number of nodes 
using namespace std;

int getSize(Node* head){    //time:O(n) space:O(h)
    if(head==NULL)
        return 0;
    return getSize(head->left)+getSize(head->right)+1;
}

int main(){
    BinaryTree tree;
    Node* head = NULL;
    head = tree.InsertNode(head,10);
    head = tree.InsertNode(head,20);
    head = tree.InsertNode(head,30);
    head = tree.InsertNode(head,40);
    head = tree.InsertNode(head,50);
    cout<<"Number of nodes = "<<getSize(head)<<endl;
    return 0;
}