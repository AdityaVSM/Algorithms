#include<bits/stdc++.h>

using namespace std;

class MyStack{
    public:
        vector<int> data;
        int top;

        MyStack(){
            top = -1;
        }

        void push(int x){
            top++;
            data.push_back(x);
        }

        int pop(){
            if(top==-1){
                cout<<"stack is empty"<<endl;
                return -1;
            }
            return data[top--];
        }

        int peek(){
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
};

int main(){
    MyStack *s = new MyStack();
    s->push(10);
    s->push(20);
    

    cout << s->peek()<<endl;
    cout<<s->isEmpty();
    return 0;
}