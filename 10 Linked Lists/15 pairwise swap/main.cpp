#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"

using namespace std;

void pairwiseSwap(Node* head){  //swap data (costly if data is big(objects, etc..) )
    Node* curr=head;
    while(curr!=NULL && curr->next != NULL){
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
}

Node* pairwiseSwap2(Node* head){
    if(head==NULL||head->next==NULL)
        return head;

    Node *curr=head->next->next;
    Node *prev=head;
    
    head=head->next;
    head->next=prev;
    
    while(curr!=NULL&&curr->next!=NULL){
        prev->next=curr->next;
        prev=curr;
    
        Node *next=curr->next->next;
        curr->next->next=curr;
        curr=next;
    }
    prev->next=curr;
    return head;
}



int main(){
    Node* head = new Node(10);

    SingleLinkedList* l1 = new SingleLinkedList(head);
    head = l1->insert_first(head,5);
    head = l1->insert_end(head,15);
    head = l1->insert_end(head,85);
    head = l1->insert_first(head,100);
    head = l1->insert_end(head,78);
    l1->traverse(head);

    pairwiseSwap(head);
    l1->traverse(head);

    head = pairwiseSwap2(head);
    l1->traverse(head);

    return 0;
}