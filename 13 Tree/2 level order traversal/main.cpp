#include<bits/stdc++.h>
#include "../BinaryTree.h"
using namespace std;

void levelOrder(Node* head){
    queue<Node*> q;
    q.push(head);
    while(!q.empty()){
        Node* node = q.front();
        cout<<node->data<<" ";
        q.pop();
        if(node->left!=NULL)
            q.push(node->left);
        if(node->right!=NULL)
            q.push(node->right);
    }
}

int main(){
    BinaryTree tree;
    Node* head = NULL;
    head = tree.InsertNode(head,10);
    head = tree.InsertNode(head,20);
    head = tree.InsertNode(head,30);
    head = tree.InsertNode(head,40);
    levelOrder(head);
    return 0;
}