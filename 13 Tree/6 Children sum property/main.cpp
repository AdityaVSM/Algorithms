#include<bits/stdc++.h>
#include "../BinaryTree.h"
using namespace std;

bool childrenSum(Node* curr){
    if(curr==NULL)  return true;
    if(curr->left==NULL && curr->right ==NULL)  return true;
    int sum=0;
    if(curr->left != NULL)  sum+=curr->left->data;
    if(curr->right != NULL) sum+=curr->right->data;

    return sum==curr->data && childrenSum(curr->left) && childrenSum(curr->right);
}

int main(){
    BinaryTree tree;
    Node* head = NULL;
    head = tree.InsertNode(head,30);
    head = tree.InsertNode(head,10);
    head = tree.InsertNode(head,20);
    head = tree.InsertNode(head,5);
    head = tree.InsertNode(head,5);
    cout<<childrenSum(head);
    return 0;
}