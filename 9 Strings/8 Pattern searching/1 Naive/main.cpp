/*
Return indices where pattern is present in main string
*/

#include<bits/stdc++.h>
using namespace std;

void naive(const string &s1, const string &s2){     //Time -> O((n-m+1)*m)
    int n = s1.length();
    int m = s2.length();
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(s2[j]!=s1[i+j])    break;
        }
        if(j==m)    cout<<i<<" ";

    }
}

int main(){
    string s1 = "AAAAA";
    string s2 = "AAA";
    naive(s1,s2);
    return 0;
}