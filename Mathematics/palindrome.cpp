#include<bits/stdc++.h>
using namespace std;
int checkPalindrome(int n){                  //O(d)  d=Number of terms in n
    int rem,reversed = 0, original = n;      //Space = O(d)
    while(n>0){
        rem = n%10;
        reversed = reversed*10 + rem;
        n /= 10;
    }
    if(original == reversed){
        return 1;
    }
    return 0;
}
int main(){
    if(checkPalindrome(121)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}