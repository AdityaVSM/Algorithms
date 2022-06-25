#include<bits/stdc++.h>
#include "../Helper/stack.h"
/*
latest one has to clone first:
([)] -> not balanced
([]) -> balanced
*/
using namespace std;

bool matching(char a, char b){
    if(a=='(' && b==')')    return true;
    if(a=='[' && b==']')    return true;
    if(a=='{' && b=='}')    return true;
    return false;
}

bool isBalanced(string s){
    MyStack<char> *stack = new MyStack<char>();
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            stack->push(s[i]);
        }
        else{
            if(stack->isEmpty())   return false;
            if(matching(stack->peek(), s[i])){
                stack->pop();
            }else{
                return false;
            }
        }
    }
    return stack->isEmpty();
}

int main(){
    string s = "{}([()])";
    cout<<isBalanced(s);
    return 0;
}