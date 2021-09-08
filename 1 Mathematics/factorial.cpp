#include<bits/stdc++.h>
using namespace std;

long iterFactorial(long n){         //O(n) best soln
    long res = 1;
    for(int i=2; i<=n; i++){
        res*=i;
    }
    return res;
}

long recurFactorial(long n){        //O(n)-time and O(n)- Auxiliary space
    if(n == 0)
        return 1;
    return n*recurFactorial(n-1);
}

int main(){
    cout<<iterFactorial(5)<<endl;
    cout<<recurFactorial(5)<<endl;
    return 0;
}