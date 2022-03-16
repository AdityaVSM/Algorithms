// check if a string is a subsequence of other
#include<bits/stdc++.h>
using namespace std;

//check is s2 is a subsequence of s1
bool isSubsequence(const string &s1,const string &s2){     //O(s1.length())
    int i=0,j=0;
    if(i<j) return false;
    while(i<s1.length()&&j<s2.length()){
        if(s1[i]==s2[j]){
            j++;
            i++;
        }
        else
            i++;
    }
    /*if(j==s2.length())
        return true;
    return false;*/
    return j==s2.length();  //same as above
}

bool recur(const string &s1, const string &s2, int n, int m){ //const becuase memory eff
    if(m==0)    return true;
    if(n==0)    return false;
    if(s1[n-1]==s2[m-1])
        return recur(s1,s2,n-1,m-1);
    else
        return recur(s1,s2,n-1,m);
}

int main(){
    string s1 = "abba";
    string s2 = "aba";
    cout<<isSubsequence(s1,s2)<<endl;
    return 0;
}