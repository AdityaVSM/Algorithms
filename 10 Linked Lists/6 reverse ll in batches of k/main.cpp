#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"

using namespace std;
/*
if k>size(ll) reverse whole ll
if k<size(ll) then k'th node weill always be new head of reversed ll
*/

Node* reverse_in_batches_recur(Node* head, int k){    //O(n) and O(n/k)
    Node* curr = head, *next = NULL, *prev = NULL;
    int count=0;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL){
        Node* reversed_head = reverse_in_batches_recur(next,k);
        head->next = reversed_head;
    }
    return prev;
}

Node* reverse_in_batches_iterative(Node* head, int k){
    Node* curr = head, *prev_first = NULL;
    bool isFirstPass = true;
    while(curr!=NULL){
        Node* first = curr, *prev = NULL;
        int count=0;        
        while(curr!=NULL && count<k){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(isFirstPass){
            head = prev;
            isFirstPass = false;
        }else{
            prev_first -> next = prev;
        }
        prev_first = first;
    }
    return head;
}

int main(){
    Node* head = new Node(10);

    SingleLinkedList* l1 = new SingleLinkedList(head);
    head = l1->insert_first(head,5);
    head = l1->insert_end(head,15);
    head = l1->insert_end(head,85);
    head = l1->insert_end(head,99);

    l1->traverse(head);

    head = reverse_in_batches_recur(head,3);
    l1->traverse(head);
    
    head = reverse_in_batches_iterative(head,3);
    l1->traverse(head);  
    return 0;
}