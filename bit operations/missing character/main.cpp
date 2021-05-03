// Find missing string between two strings (only one character missing)

#include<bits/stdc++.h>
using namespace std;
char findTheDifference(string s, string t) {
    int sum = 0;
    for(int i = 0; i <t.length(); i++){
        sum = sum + ((int)t[i] - (int)s[i]);
    }
    return char(sum);
}

int main(){
    cout<<findTheDifference("abc","cbda")<<endl;
    cout<<findTheDifference("","a")<<endl;
    return 0;
}