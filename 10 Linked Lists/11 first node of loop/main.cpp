#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"

using namespace std;

Node* firstNodeOfLoop(Node* head){
    Node* slow=head, *fast = head;
    bool loopExists = false;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            loopExists = true;
            break;
        }
    }
    if(loopExists){
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    cout<<"Loop doesn't exists\n";
    return NULL;
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

    cout<<"First node of loop is "<<firstNodeOfLoop(head)->data<<endl;
    return 0;
}