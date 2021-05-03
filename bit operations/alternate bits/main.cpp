// CHECK IF BINARY REPRESENTATION OF GIVEN NUMBER HAS ALTERNATE 1'S and 0'S

#include<bits/stdc++.h>
using namespace std;
bool hasAlternatingBits(int n){
    int temp = (n ^ (n >> 1));
    return (temp & (temp+1)) == 0;
}
int main(){
    cout<<hasAlternatingBits(5)<<endl;
    cout<<hasAlternatingBits(4)<<endl;
    return 0;
}