#include<bits/stdc++.h>
using namespace std;

void freq(string s){    //O(n) time O(1) space because alwaya array size(for small letters)=26
    int freq[26] = {0};
    for(int i=0;i<s.length();i++){
        freq[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(freq[i] > 0){
            cout<<(char)(i+'a')<<" "<<freq[i]<<endl;
        }
    }
}

int main(){
    string s = "aditya";
    freq(s);
    return 0;
}