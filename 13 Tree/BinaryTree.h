#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};


class BinaryTree{
    public:
        
        Node* CreateNode(int data){
            Node *newNode = new Node();
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        Node* InsertNode(Node* root, int data){
            if (root == NULL) {
                root = CreateNode(data);
                return root;
            }
            queue<Node*> q;
            q.push(root);
        
            while (!q.empty()) {
                Node* temp = q.front();
                q.pop();
        
                if (temp->left != NULL)
                    q.push(temp->left);
                else {
                    temp->left = CreateNode(data);
                    return root;
                }
        
                if (temp->right != NULL)
                    q.push(temp->right);
                else {
                    temp->right = CreateNode(data);
                    return root;
                }
            }
            return NULL;
        }

        //Height = max number of nodes time:O(N) space:O(H)
        int getHeight(Node* head){
            if(head==NULL)
                return 0;
            return max(getHeight(head->left), getHeight(head->right))+1;
        }


        //traversal time:O(number of nodes) space:O(height)
        void preOrder(Node* head){  
            if(head==NULL)
                return;
            cout<<head->data<<" ";
            preOrder(head->left);
            preOrder(head->right);
        }

        void inOrder(Node * head){
            if(head==NULL)
                return;
            inOrder(head->left);
            cout<<head->data<<" ";
            inOrder(head->right);
        }

        void postOrder(Node* head){
            if(head==NULL)
                return;
            postOrder(head->left);
            postOrder(head->right);
            cout<<head->data<<" ";
        }
};



// int main(){
//     BinaryTree tree;
//     Node* head = NULL;
//     head = tree.InsertNode(head,10);
//     head = tree.InsertNode(head,20);
//     head = tree.InsertNode(head,30);
//     head = tree.InsertNode(head,40);
//     tree.postOrder(head);
//     cout<<"\nHeight is "<<tree.getHeight(head)<<endl;
//     return 0;
// }