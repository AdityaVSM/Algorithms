#include<bits/stdc++.h>
#include "../Helper/queue.h"

using namespace std;
/*
Given a number n, print first n numbers(increasing order) that contain only digits{5,6}
ex : n=4:
op = 5,6,55,56
*/

void print(int n){
    Queue<string> q;
    q.enqueue("5");
    q.enqueue("6");
    for(int i=0;i<n;i++){
        string curr = q.getFront();
        cout<<curr<<" ";
        q.dequeue();
        q.enqueue(curr+"5");
        q.enqueue(curr+"6");
    }
}

int main(){
    print(4);
    return 0;
}