#include<bits/stdc++.h>
using namespace std;

void subString(string &s, int index=0, string cur=""){
    if(index == s.length()){
        cout<<cur<<" ";
        return;
    }
    subString(s, index+1, cur);
    subString(s, index+1, cur+s[index]);
}

int main(){
    vector<int> arr = {4,1,2,1,2};
    string s ="ABC";
    subString(s);
    return 0;
}