#include<bits/stdc++.h>
using namespace std;

//Naive O(number of bits in bin rep of number)
int setBits1(int n){
    int count = 0;
    while(n>0){
        if(n%2 == 0)   //to Check if first(from right of our side) bit of bin rep of n is SET
            count++;
        n /= 2;        //to remove first(from right of our side) bit of bin rep of n after checking if it is SET
    }
    //Alternatively use bitwise operation
    // while(n>0){          
    //     if((n&1) == 1)
    //         count++;
    //     n = n>>1;
    // }
    return count;
}

//Brian kernigam algo O(set bit count)
int setBits2(int n){
    int count = 0;
    while(n>0){
        n = n&(n-1);
        count++;
    }
    return count;
}

int main(){
}
