#include<bits/stdc++.h>

using namespace std;

template <typename T> class MyStack{
    public:
        vector<T> data;
        int top;

        MyStack(){
            top = -1;
        }

        void push(T x){
            top++;
            data.push_back(x);
        }

        void pop(){
            if(top==-1){
                cout<<"stack is empty"<<endl;
                return;
            }
            data.erase(data.begin()+top);
            top--;
        }

        T peek(){
            if(top==-1){
                cout<<"stack Underflow"<<endl;
                return -1;
            }
            return data[top];
        }

        int size(){
            return top+1;
        }

        bool isEmpty(){
            return top==-1;
        }

        void display(){
            for(T x : data){
                cout<<x<<"->";
            }
            cout<<endl;
        }
};

// int main(){
//     MyStack *s = new MyStack();
//     s->push(10);
//     s->push(20);
    

//     cout << s->peek()<<endl;
//     cout<<s->isEmpty();
//     return 0;
// }