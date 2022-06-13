#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"

using namespace std;

bool isLoop(Node* head){    //Modifies links in ll
    Node* temp = new Node();
    Node* curr = head;
    while(curr!=NULL){
        if(curr->next == NULL)
            return false;
        if(curr->next == temp)
            return true;
        Node *curr_next = curr->next;
        curr->next = temp;
        curr = curr_next;
    }
    return false;
}

bool isLoopBetter(Node* head){
    unordered_set<Node*> s; 
    for(Node* curr = head; curr != NULL; curr = curr->next) {  
        if (s.find(curr) != s.end()) 
            return true; 
        s.insert(curr); 
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


    // l1->traverse(head);
    cout<<isLoopBetter(head)<<endl; //This call comes first because next call modifies link in ll
    cout<<isLoop(head)<<endl;

    return 0;
}