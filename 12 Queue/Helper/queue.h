#include<bits/stdc++.h>
using namespace std;

template <typename T> class Queue{
    public:
        vector<T> data;
        int size;

        Queue(){
           size=0; 
        }
        void enqueue(T x){
            size++;
            data.push_back(x); 
        };
        void dequeue(){
            if(size == 0){
                cout<<"Queue is empty"<<endl;
                return;
            }
            data.erase(data.begin());
            size--;
        };
        T getFront(){
            if(size==0){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return data[0];
        };
        T getRear(){
            if(size==0){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return data[size-1];
        };
        bool isEmpty(){
            return size==0;
        };
        int getSize(){
            return size;
        };
};

// int main(){
//     Queue<int> q;
//     q.enqueue(12);
//     cout<<q.getFront()<<endl;
//     cout<<q.getRear()<<endl;
//     q.dequeue();
//     cout<<q.getFront()<<endl;
//     return 0;
// }