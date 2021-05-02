#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(int n){
    if(n==0) return 0;
    return (n%10)+sumOfDigits(n/10);
}

int main(){
    vector<int> arr = {4,1,2,1,2};
    cout<<sumOfDigits(22)<<endl;
    return 0;
}