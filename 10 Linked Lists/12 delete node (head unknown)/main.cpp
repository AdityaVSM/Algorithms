#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"

using namespace std;
//Delete a node whosse reference is known head unknonwn

/*
Copy data of next node to given node
delete next node
*/

void deleteNode(Node* toDelete){    //Cannot delete last node
    Node* temp = toDelete -> next;
    toDelete->data = temp->data;
    toDelete->next = temp->next;
    delete(temp);
}

int main(){
    Node* head = new Node(10);

    SingleLinkedList* l1 = new SingleLinkedList(head);
    head = l1->insert_first(head,5);
    head = l1->insert_end(head,15);
    head = l1->insert_end(head,85);

    l1->traverse(head);
    deleteNode(head->next);
    l1->traverse(head);


    return 0;
}