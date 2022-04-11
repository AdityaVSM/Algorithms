/*
Works when characters in small text(pattern) are distinct
*/
#include<bits/stdc++.h>
using namespace std;

void naive(const string &s1, const string &s2){
    int n = s1.length();
    int m = s2.length();
    for(int i=0;i<=n-m){
        int j;
        for(j=0;j<m;j++){
            if(s1[i+j]!=s2[j])
                break;
            if(j==m)
                cout<<i<<" ";
            if(j==0)
                i++;
            else
                i+=j;
        }
    }
}

int main(){
    string s1 = "ABCABCDABCD";
    string s2 = "ABCD";
    naive(s1,s2); 
    return 0;
}