/*
Given a sorted ll, insert an ele to it such that it remains sorted
*/
#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"
using namespace std;

int main(){
    Node* head = new Node(10);

    SingleLinkedList* l1 = new SingleLinkedList(head);
    l1->traverse(head);

    head = l1->insert_first(head,5);
    l1->traverse(head);
    
    head = l1->insert_end(head,15);
    l1->traverse(head);

    head = l1->delete_first(head);
    l1->traverse(head);

    head = l1->insert_first(head,85);
    l1->traverse(head);

    head = l1->delete_end(head);
    l1->traverse(head);

    head = l1->delete_first(head);
    l1->traverse(head);

    return 0;
}