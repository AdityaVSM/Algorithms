// Print all permutations of a given string.
#include<bits/stdc++.h>
using namespace std;

void swap(char *a, char*b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
void permute(string &s, int i=0){
    if( i== s.length()-1){
        cout<<s<<" ";
        return;
    }
    for(int j=i;j<s.length();j++){
        swap(s[i], s[j]);
        permute(s,i+1);
        swap(s[j],s[i]);
    }
}

int main(){
    string s = "ABC";
    permute(s);
    return 0;
}