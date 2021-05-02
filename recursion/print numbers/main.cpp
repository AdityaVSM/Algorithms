#include<bits/stdc++.h>
using namespace std;

void nToOne(int n){
    if(n==0) return;
    cout<<n<<" ";
    nToOne(n-1);
}
void oneToN(int n){
    if(n == 0) return;
    oneToN(n-1);
    cout<<n<<" ";
}

int main(){
    nToOne(5);
    cout<<endl;
    oneToN(5);
    return 0;
}