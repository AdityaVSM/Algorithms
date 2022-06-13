#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"

using namespace std;
/*
Floyd's cycle rule:
slow -> one jump
fast -> two jump at a time

if loop:
    slow == fast at some time
*/

bool loopExists(Node* head){
    Node* slow = head, *fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

int main(){
    Node* head = new Node(10);

    SingleLinkedList* l1 = new SingleLinkedList(head);
    head = l1->insert_first(head,5);
    head = l1->insert_end(head,15);
    head = l1->insert_end(head,85);

    l1->traverse(head);

    // Node* t1 = head->next;  //2'nd node
    // Node* t2 = head->next->next->next;  //last node

    head->next->next->next->next = head->next;

    cout<<loopExists(head)<<endl;
    return 0;
}