//Anagram = every char appearing in 1 string should also appear in 2 and freq should
//          also be equal but order may differ
#include<bits/stdc++.h>
using namespace std;

bool naive(string &s1, string &s2){     //O(n*logn)
    if(s1.length()!=s2.length())    return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1==s2;
}

bool efficient1(const string &s1, const string &s2){    //O(n)
    if(s1.length()!=s2.length())    return false;
    int n = s1.length();
    int freq[256] = {0};
    for(int i=0;i<256;i++){
        freq[s1[i]-'a']++;
    }
    for(int i=0;i<256;i++){
        if(freq[s2[i]-'a']==0)
            return false;
        if(freq[s2[i]-'a']>0)
            freq[s2[i]]--;
    }
    return true;
}

bool efficient2(const string &s1, const string &s2){    //O(n)
    if(s1.length()!=s2.length())    return false;
    int n = s1.length();
    int freq[256] = {0};
    for(int i=0;i<256;i++){
        freq[s1[i]]++;
        freq[s2[i]]--;
    }
    for(int i=0;i<256;i++){
        if(freq[i]!=0)
            return false;
    }
    return true;
}

int main(){
    string s1 = "helloo";
    string s2 = "eholll";
    cout<<efficient1(s1,s2)<<endl;
    return 0;
}