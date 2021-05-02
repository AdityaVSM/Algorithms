#include<bits/stdc++.h>
using namespace std;

bool is2Power(int n){               //O(n)
    if(n == 0) return false;
    while (n!=1){
        if(n %2 !=0) return false;
        n = n / 2;
    }
    return true;
}

//Using Brian kernigam algo         //O(set bit count)
bool is2Power2(int n){              
    if(n == 0) return false;
    return(n&(n-1) == 0);
    // return((n!=0) && (n & (n-1) == 0))
}


int main(){
    int n = 4;
    cout<<is2Power(6)<<" "<<is2Power2(6)<<endl;
    return 0;
    cout<<(2&3==0)<<endl;
}