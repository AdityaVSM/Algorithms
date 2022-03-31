/*
    return index of leftmost repeating char
    ex:
        1) geeksforgeeks -> 0 because of (g)
        2) abba -> 0 because of (a)
        3) abbd -> 1 because of (b)
        4) abcd -> -1 because none
*/
#include<bits/stdc++.h>
using namespace std;

//naive --> O(n^2) check all char with individual char
int eff1(const string &s){  //O(1)
    int n = s.length();
    int freq[256] = {0};
    for(int i=0;i<26;i++){
        freq[s[i]-'a']++;
    }
    for(int i=0;i<256;i++){
        if(freq[i]>1)
            return s.find((char)i+'a');
    }
    return -1;
}
int eff2(const string &s){  //O(1)
    int n = s.length();
    int freq[256] = {0};
    for(int i=0;i<n;i++){
        freq[s[i]]++;
    }
    for(int i=0;i<n;i++){
        if(freq[s[i]]>1)
            return i;
    }
    return -1;
}


int main(){
    string s = "abba";
    cout<<eff2(s)<<endl;
    return 0;
}