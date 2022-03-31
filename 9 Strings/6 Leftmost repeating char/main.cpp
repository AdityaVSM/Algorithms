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

    


int main(){
    string s = "abba";
    cout<<naive(s)<<endl;
    return 0;
}