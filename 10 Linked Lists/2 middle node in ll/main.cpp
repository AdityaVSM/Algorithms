#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"

using namespace std;

Node* middle_ele(Node* head){
    Node* fast = head;
    Node* slow = head;
    if(head==NULL){
        cout<<"No elements in linked list";
        return NULL;
    }
    if(head->next == NULL)
        return head;
    if(head->next->next == NULL)
        return head->next;
    while(fast->next->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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


    cout<<"Middle element is "<< middle_ele(head)->data<<endl;


    return 0;
}