#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"

using namespace std;
Node * reverse(Node* head){
    //reversing the links
    if(head==NULL)
        return NULL;
    if(head->next == NULL)
        return head;
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL){
        Node* next = curr -> next;
        curr->next = prev;
        
        prev = curr;    //this before next line else curr changes
        curr = next;
    }
    return prev;    //New head
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