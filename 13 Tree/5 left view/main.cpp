#include<bits/stdc++.h>
#include "../BinaryTree.h"

using namespace std;
//To print leftmost node in each level
void printLeft(Node *root){
    if(root==NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while(q.empty()==false){
        int count=q.size();
        for(int i=0;i<count;i++){
            Node *curr=q.front();
            q.pop();
            if(i==0)
                cout<<curr->data<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
}

int main(){
    BinaryTree tree;
    Node* head = NULL;
    head = tree.InsertNode(head,10);
    head = tree.InsertNode(head,20);
    head = tree.InsertNode(head,30);
    head = tree.InsertNode(head,40);
    head = tree.InsertNode(head,50);
    head = tree.InsertNode(head,60);
    head = tree.InsertNode(head,70);
    head = tree.InsertNode(head,80);
    head = tree.InsertNode(head,90);

    printLeft(head);
    return 0;
}