#include<bits/stdc++.h>
using namespace std;

void powerSet(string s){
    int n = s.length();
    int size = pow(2,n);
    for(int counter = 0; counter < size; counter++){
        for(int i=0; i<n; i++){
            if((counter & (1<<i)) != 0)
                cout<<s[i];
        }
        cout<<" ";
    }
}

int main(){
    string s = "abc";
    powerSet(s);
    return 0;
}