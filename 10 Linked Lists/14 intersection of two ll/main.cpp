#include<bits/stdc++.h>
#include "../Helper/SingleLinkedList.h"

using namespace std;

/*
Given two ll find intersecting point
ex:
l1 : 5->6->7->8->9->10
l2 : 15->8->9->10
ans : 8
*/

//Method1 : create Hashset to store first ll ele and check through second ll
Node* intersection1(Node* first, Node*second) {  //O(m+n) time ans O(m) space
    Node* curr = first;
    unordered_set<int> set;
    while(curr != NULL) {
        set.insert(curr->data);
        curr =curr->next;
    }
    curr = second;
    while (curr!=NULL){
        if(set.find(curr->data) != set.end()){
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

/*Method2 : 
c1 = len(first), c2 = len(second)
temp = abs(c2-c1)
traverse longer list temp times 
traverse both list simultaneously until both are same
*/
Node* intersection2(Node* first, Node* second){ //O(m-n) O(1)
    int m=0,n=0;
    Node* curr1=NULL, *curr2=NULL;
    Node*temp = first;
    while(temp != NULL){ 
        m++;
        temp = temp->next;
    }

    temp = second;
    while(temp != NULL){  
        n++;
        temp = temp->next;
    }

    Node* other = NULL;
    if(m>n) {
        temp = first;
        other = second;
    }else {
        temp = second;
        other = first;
    }
    
    int count=0;
    while(count<abs(m-n)){
        temp = temp->next;
        count++;
    }

    while(other != NULL && temp != NULL){
        if(other->data==temp->data) return other;
        temp = temp->next;
        other = other->next;
    }
    return NULL;
}

int main(){
    Node* first = new Node(5);
    SingleLinkedList* l1 = new SingleLinkedList(first);
    first = l1->insert_end(first,6);
    first = l1->insert_end(first,8);
    first = l1->insert_end(first,9);
    first = l1->insert_end(first,10);
    l1->traverse(first);

    Node* second = new Node(15);
    SingleLinkedList* l2 = new SingleLinkedList(second);
    second = l2->insert_end(second,8);
    second = l2->insert_end(second,9);
    second = l2->insert_end(second,10);
    l2->traverse(second);

    cout << "intersection point is "<< intersection2(first,second)->data <<endl;

    return 0;
}