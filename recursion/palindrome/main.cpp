#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str, int start, int end){
    if(start >= end) return true;
    if(str[start] == str[end]){
        return isPalindrome(str,start+1,end-1);
    }
    return false;
    //return (str[start] == str[end] && isPalindrome(str,start+1,end-1));
}
int main(){
    string str = "abcba";
    cout<<isPalindrome(str,0,4)<<endl;
    return 0;
}