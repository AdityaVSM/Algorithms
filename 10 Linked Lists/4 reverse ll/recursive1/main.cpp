#include<bits/stdc++.h>
#include "../../Helper/SingleLinkedList.h"

using namespace std;

Node* reverse(Node* head){
    if(head==NULL || head->next==NULL)  return head;
    Node* next_head = reverse(head->next);
    Node* next_tail = head->next;
    next_tail->next = head;
    head->next = NULL;
    return next_head;

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

    head = reverse(head);
    l1->traverse(head);
    return 0;
}