/*
given teo strings check if s2 is substring or anagram of substing of s2
s1 = "aditya"
s2 = "yti"
res -> true. "yti" is a permutation of "ity"

s2 = "ati"
res -> false. even though a,t,i are present but they are not contiguous in s1
*/

#include<bits/stdc++.h>
using namespace std;

bool are_same(int arr1[], int arr2[], int n, int m){
    if (n != m)
        return false;
 
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
 
    for (int i = 0; i < n; i++)
        if (arr1[i] != arr2[i])
            return false;
 
    return true;
}
bool check_for_anagram(string &s1, string &s2){
    int freq_patt[256] = {0};
    int freq_text[256] = {0};

    int n = s1.length();
    int m = s2.length();
    
    for(int i=0;i<m;i++){
        freq_patt[s2[i]]++;
        freq_text[s1[i]]++;
    }

    for(int i=m;i<n;i++){
        if(are_same(freq_patt, freq_text, m, m))    return true;

        freq_text[s1[i]]++;
        freq_text[s1[i-m]]--;
    }
    return false;
}

int main(){
    string s1 = "aditya";
    string s2 = "tiy";
    cout<<check_for_anagram(s1,s2);
    return 0;
}