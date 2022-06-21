#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"

using namespace std;

/*Use stack
-> push all ele in ll to stack
-> start popping ele and compare with ll ele
->      any mismatch found return false
-> return true
*/
bool check_palindrome_naive(Node* head){
    stack<int> st;
    Node* curr = head;
    while(curr != NULL){
        st.push(curr->data);
        curr = curr->next;
    }

    curr = head;
    while(curr!= NULL){
        if(st.top() != curr->data)
            return false;
        st.pop();
        curr = curr->next;
    }
    return true;
}

/*
->find middle
-> reverse ll after middle seperately
-> compare first node and first node after middle
-> if same:
        repeat step 3
-> else
        not a palindrome
*/
Node * reverse(Node* head){
    //reversing the links
    if(head==NULL)
        return NULL;
    if(head->next == NULL)
        return head;
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL){
        Node* next = curr -> next;
        curr->next = prev;
        
        prev = curr;    //this before next line else curr changes
        curr = next;
    }
    return prev;    //New head
}
bool check_for_palindrome_efficient(Node * head){
    if(head==NULL)  return true;
    Node* slow = head, *fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* rev = reverse(slow->next);
    Node* curr = head;
    while(rev != NULL){
        if(rev->data != curr->data)
            return false;
        rev = rev->next;
        curr = curr->next;
    }
    return true;
}

int main(){
    Node* head = new Node(5);
    SingleLinkedList* l1 = new SingleLinkedList(head);
    head = l1->insert_end(head,6);
    head = l1->insert_end(head,8);
    head = l1->insert_end(head,6);
    head = l1->insert_end(head,8);

    l1->traverse(head);

    cout << check_palindrome_naive(head)<<endl;
    cout << check_for_palindrome_efficient(head)<<endl;

    return 0;
}