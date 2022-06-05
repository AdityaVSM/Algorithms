#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node(){
            data=0;
            next = NULL;
        }
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

class SingleLinkedList{
    Node * head;
    public:
        SingleLinkedList(){
            this->head = NULL;
        }
        SingleLinkedList(Node * head){
            this->head = head;
        }
        void traverse(Node* head);
        Node* insert_first(Node* head, int data); 
        Node* insert_end(Node* head, int data); 
        Node* delete_first(Node* head);
        Node* delete_end(Node* head); 
};

void SingleLinkedList :: traverse(Node* head){
    if(head == NULL){
        cout<<"No elements in ll";
        return;
    }
    Node* curr = head;
    while(curr != NULL){
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout<<endl;
}

Node* SingleLinkedList :: insert_first(Node* head, int data){
    Node* newNode = new Node(data);
    if(head==NULL)
        return newNode;
    newNode->next = head;
    // head = newNode;
    return newNode;
}

Node* SingleLinkedList :: insert_end(Node* head, int data){
    Node* newNode = new Node(data);
    if(head==NULL)
        return newNode;
    if(head->next==NULL){
        head->next=newNode;
        return head;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next=newNode;
    return head;
}

Node* SingleLinkedList :: delete_first(Node* head){
    if(head == NULL){
        cout<<"No elements in ll";
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node* temp = head->next;
    delete(head);
    return temp;
}

Node* SingleLinkedList :: delete_end(Node* head){
    if(head == NULL){
        cout<<"No elements in ll";
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    // if(head->next->next == NULL){
    //     head->next = NULL;
    //     delete head->next;
    //     return head;
    // }
    Node* curr = head;
    while (curr->next->next != NULL)
        curr = curr->next;
 
    delete (curr->next);
 
    curr->next = NULL;
 
    return head;
}

/*
int main(){
    Node* head = new Node(10);

    SingleLinkedList* l1 = new SingleLinkedList(head);
    l1->traverse(head);

    head = l1->insert_first(head,5);
    l1->traverse(head);
    
    head = l1->insert_end(head,15);
    l1->traverse(head);

    head = l1->delete_first(head);
    l1->traverse(head);

    head = l1->insert_first(head,85);
    l1->traverse(head);

    head = l1->delete_end(head);
    l1->traverse(head);

    head = l1->delete_first(head);
    l1->traverse(head);

    return 0;
}
*/
