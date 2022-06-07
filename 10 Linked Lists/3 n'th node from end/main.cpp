#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"
using namespace std;


Node* n_node_from_last(Node * head, int pos_from_last){
    Node*curr=head;
    /*N'th node from end = size-n+1 node from start*/
    int size=1;
    while(curr != NULL){
        size++;
        curr = curr ->next;
    }
    curr=head;
    int count_=1;
    int pos_from_beg = size-pos_from_last;
    while(curr!=NULL && count_<pos_from_beg){
        curr = curr->next;
        count_++;
    }
    return curr;
}

Node* efficient(Node* head, int pos_from_last){
    Node*fast = head;
    Node* slow = head;
    int count=0;
    while(fast!=NULL && count<pos_from_last){
        fast = fast->next;
        if(fast == NULL){
            cout<<"pos_from_last is greater than size"<<endl;
            return NULL;
        }
        count++;
    }
    while(fast != NULL){
        fast = fast ->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    Node* head = new Node(10);

    SingleLinkedList* l1 = new SingleLinkedList(head);
    l1->traverse(head);

    head = l1->insert_first(head,5);
    l1->traverse(head);
    
    head = l1->insert_end(head,15);
    l1->traverse(head);

    // head = l1->delete_first(head);
    // l1->traverse(head);

    head = l1->insert_end(head,85);
    l1->traverse(head);


    cout<<"n_node_from_last is "<< n_node_from_last(head,2)->data << endl;
    cout<<"n_node_from_last is "<< efficient(head,2)->data << endl;


    return 0;
}