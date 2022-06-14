#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"
using namespace std;

int lenOfLoop(Node* head){
    Node*slow=head, *fast=head;
    bool loopExists=false;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            loopExists = true;
            break;
        }
    }
    if(loopExists){
        int count = 1;
        slow = slow->next;
        while(slow!=fast){  //Keep one pointer in fixed place and move other pointer until they meet
            slow = slow->next;
            count++;
        }
        return count;
    }
    return 0;
}

int main(){
    Node* head = new Node(10);

    SingleLinkedList* l1 = new SingleLinkedList(head);
    head = l1->insert_first(head,5);
    head = l1->insert_end(head,15);
    head = l1->insert_end(head,85);

    l1->traverse(head);

    head->next->next->next->next = head->next;
    // l1->traverse(head); //runs infinetly

    cout<<"Length of loop is "<<lenOfLoop(head)<<endl;

    return 0;
}