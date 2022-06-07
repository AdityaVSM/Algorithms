/*
Given a sorted ll, insert an ele to it such that it remains sorted
*/
#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"
using namespace std;

Node* sorted_insert(Node* head, int new_data){
    Node* new_node = new Node(new_data);
    Node* curr = head;
    if(head==NULL){
        cout<<"No elements in linked list";
        head = new_node;
        return head;
    }
    if(head->data > new_data){
        new_node->next = head;
        head = new_node;
        return head;
    }
    while(curr->next!=NULL && curr->next->data<new_data){
        curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
    return head;
}

int main(){
    Node* head = new Node(10);

    SingleLinkedList* l1 = new SingleLinkedList(head);
    l1->traverse(head);

    head = l1->insert_first(head,5);
    l1->traverse(head);
    
    head = l1->insert_end(head,15);
    l1->traverse(head);

    // head = l1->delete_first(head);
    // l1->traverse(head);

    head = l1->insert_end(head,85);
    l1->traverse(head);

    head = sorted_insert(head,20);
    l1->traverse(head);

    return 0;
}