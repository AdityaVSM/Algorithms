#include<bits/stdc++.h>
#include "../Helper/queue.h"

using namespace std;

void reverse(Queue<int> &queue){
    if(queue.isEmpty())
        return;
    int x = queue.getFront();
    queue.dequeue();
    reverse(queue);
    queue.enqueue(x);
}


int main(){
    Queue <int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    reverse(q);
    while(!q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.dequeue();
    }
    return 0;
}