#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"

using namespace std;
/*
All even value should come first then all odd values (Maintain relative order)
i/p := 17->15->8->12->10->5->4
o/p := 8->12->10->4->17->15->5
*/
Node* seggregateEvenOdd(Node* head){
    Node* even_start=NULL, *even_end=NULL;
    Node* odd_start=NULL, *odd_end=NULL;
    Node* curr = head;
    
    while(curr != NULL) {
        int x = curr->data;
        if(x%2 == 0) {
            if(even_start==NULL){
                even_start=curr;
                even_end=even_start;
            }else{
                even_end->next=curr;
                even_end = even_end->next;
            }
        }else{
            if(odd_start==NULL){
                odd_start=curr;
                odd_end=odd_start;
            }else{
                odd_end-> next = curr;
                odd_end = odd_end->next;
            }
        }
        curr = curr->next;
    }

    if(odd_start == NULL || even_start == NULL)
        return head;

    even_end->next = odd_start;
    odd_end->next = NULL;
    return even_start;
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

    head = seggregateEvenOdd(head);
    l1->traverse(head);
    return 0;
}