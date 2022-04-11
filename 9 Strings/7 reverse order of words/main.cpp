/*
Given a sentence reverse the order of words in the sentence
*/
#include<bits/stdc++.h>
using namespace std;

//Naive -> use stack

//efficient -> reverse chars in individual words and reverse whole sentence
void reverse_(string &s,int start,int end){
    while(start<end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
}
void eff(string &s){
    int n = s.length();
    int start=0;
    for(int end=0; end<n;end++){
        if(s[end]==' '){
            reverse_(s,start,end-1);
            start = end+1;
        }
    }
    reverse_(s,start,n-1); //To reverse last word
    reverse_(s,0,n-1); //reverse whole sentence
    cout<<s<<endl;
}

int main(){
    string s = "Aditya VSM";
    eff(s);
    return 0;
}