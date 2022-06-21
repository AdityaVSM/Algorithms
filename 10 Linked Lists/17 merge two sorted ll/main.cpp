#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"
/*
Use same space i,e do not create any new node
*/
using namespace std;

Node* merge(Node* first, Node* second){     //O(m+n) time
    if(first == NULL)   return second;
    if(second == NULL)  return first;

    Node* head=NULL, *tail=NULL;
    if(first->data <= second->data){
        head = tail = first;
        first = first->next;
    }else{
        head = tail = second;
        second = second -> next;
    }

    while(first != NULL && second != NULL){
        if(first->data <= second->data){
            tail->next = first;
            tail = first;
            first = first->next;
        }else{
            tail->next = second;
            tail = second;
            second = second->next;
        }        
    }
    if(first == NULL)   tail->next = second;
    else tail->next = first;

    return head;
}

int main(){
    Node* first = new Node(5);
    SingleLinkedList* l1 = new SingleLinkedList(first);
    first = l1->insert_end(first,6);
    first = l1->insert_end(first,8);
    first = l1->insert_end(first,9);
    first = l1->insert_end(first,10);
    l1->traverse(first);

    Node* second = new Node(7);
    SingleLinkedList* l2 = new SingleLinkedList(second);
    second = l2->insert_end(second,18);
    second = l2->insert_end(second,29);
    second = l2->insert_end(second,120);
    l2->traverse(second);

    Node* merged = merge(first, second);
    SingleLinkedList* l3 = new SingleLinkedList(merged);
    l3->traverse(merged);
    return 0;
}