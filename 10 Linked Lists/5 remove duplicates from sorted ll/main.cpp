#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"

using namespace std;

void remove_dup(Node*head){ //No need to return head as head never changes
    if(head==NULL){
        cout << "LL is empty \n";
        return;
    }
    Node* curr = head;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->data == curr->next->data){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            // curr->next->next = NULL;
            delete(temp);
        }
        else
            curr = curr->next;
    }
}
int main(){
    Node* head = new Node(10);

    SingleLinkedList* l1 = new SingleLinkedList(head);
    head = l1->insert_first(head,5);
    head = l1->insert_end(head,15);
    head = l1->insert_end(head,85);
    head = l1->insert_end(head,85);
    head = l1->insert_end(head,85);

    l1->traverse(head);

    remove_dup(head);
    l1->traverse(head);    
    return 0;
}