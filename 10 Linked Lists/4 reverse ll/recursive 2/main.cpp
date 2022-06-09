#include<bits/stdc++.h>
#include "../../Helper/SingleLinkedList.h"

using namespace std;

Node* reverse(Node* curr, Node*prev){
    if(curr==NULL)  return prev;
    Node* next = curr->next;
    curr->next = prev;
    return reverse(next, curr);
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

    head = reverse(head, NULL);
    l1->traverse(head);
    return 0;
}