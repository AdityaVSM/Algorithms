#include<bits/stdc++.h>
#include "../BinaryTree.h"

using namespace std;

int getMax(Node* head){
    if(head==NULL)
        return INT_MIN;
    return max(head->data, max(getMax(head->left), getMax(head->right)));
}

int main(){
    BinaryTree tree;
    Node* head = NULL;
    head = tree.InsertNode(head,10);
    head = tree.InsertNode(head,20);
    head = tree.InsertNode(head,30);
    head = tree.InsertNode(head,40);
    head = tree.InsertNode(head,50);
    cout<<"Maximum element is "<<getMax(head)<<endl;
    return 0;
}