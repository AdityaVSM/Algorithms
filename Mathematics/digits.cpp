#include<bits/stdc++.h>

using namespace std;

int iterativeDigitCount(long long n){       //O(d)(d=number of digits)
    int count = 0;
    while(n>0){
        n /= 10;
        count++;
    }
    return count;
}
int recursiveDigitCount(long long n){       //O(d)
    if(n==0)
        return 0;
    return 1+recursiveDigitCount(n/10);
}
int logarthmicDigitCount(long long n){      //O(1)
    return floor(log10(n)) + 1 ;
}
int main(){
    long long n = 1212;
    cout << iterativeDigitCount(n) << endl;
    cout << recursiveDigitCount(n) << endl;
    cout << logarthmicDigitCount(n) << endl;
    return 0;
}