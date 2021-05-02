/*
There are n people standing in a circle, we need to kill k'th person in every iteration and do it in circular way only.
Find the position of survivor 
*/

#include<bits/stdc++.h>
using namespace std;

int josephus(int n, int k){
    if(n == 1) return 0;
    return ((josephus(n-1,k))+k)%n;
}

int main(){
    cout<<josephus(7,3)<<endl;
    return 0;
}