#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"

using namespace std;
/*
do floyd's cycle loop detection
-> move slow to head
-> keep incementing slow and fast by 1 node
-> when slow and fast meet that's where loop is linked
*/
Node* removeLoop(Node* head){
    Node* slow=head, *fast=head;
    bool isLoop = false;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            isLoop = true;
            break;
        }
    }
    if(isLoop){
        slow = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
    return head;
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
    // l1->traverse(head); //runs infinetly

    head = removeLoop(head);

    l1->traverse(head);

    return 0;
}