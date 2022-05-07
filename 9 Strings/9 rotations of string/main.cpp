/*
Given two strings check if one is rotation of the other
s1="abcd", s2="cdab"
res->true
s2 obtained by rotating s1 by 2 times counterclockwise
*/
#include<bits/stdc++.h>
using namespace std;

bool check_for_rotation(string &s1, string &s2){    
    if(s1.length() != s2.length())  return false;
    string s3 = s1+s1;
    return (s3.find(s2) != string::npos);
}

int main(){
    string s1 = "aditya";
    string s2 = "tyaadi";
    cout<<check_for_rotation(s1,s2);
    return 0;
}