#include<bits/stdc++.h>
using namespace std;

//DigitalRoot of a number is the recursive sum of its digits until we get a single digit number.

int digitalNumber(int n){
    if(n < 10) return n;
    return digitalNumber(n%10 + n/10);
}
int main(){
    cout<<digitalNumber(123)<<endl;
    cout<<digitalNumber(0)<<endl;
    return 0;
}