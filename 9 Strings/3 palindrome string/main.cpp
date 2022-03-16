#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){    //O(n)
    int l=0,r=s.length()-1;
    while(l<=r){
        if(s[l]!=s[r])
            return false;
        l++;
        r--;
    }
    return true;
}
int main(){
    string s = "abccba";
    cout<<isPalindrome(s)<<endl;
    return 0;
}