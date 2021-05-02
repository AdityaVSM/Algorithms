#include<bits/stdc++.h>
using namespace std;

long long iterFactorial(int n){
    long long res = 1;
    for(int i=2; i<=n; i++)
        res *= i;
    return res;
}
int trailingZero(int n){            //O(n)  causes overflow even for small numbers like 100
    long long factorial = iterFactorial(n);
    int count = 0;
    while(factorial%10 == 0){
        count++;
        factorial /=10;
    }
    return count;    
}
int trailingZero2(int n){           //O(n) causes overflow even for small numbers like 100
    long long factorial = iterFactorial(n);
    int count = 0;
    int rem;
    while(factorial > 0){
        rem = factorial % 10;
        if(rem != 0)
            break;
        count++;
        factorial /= 10;
    }
    return count;
}
int trailingZero3(int n){           //O(log(5)n)=O(log n)  best approach
    int res = 0;
    for(int i=5; i<=n; i*=5)
        res += n/i;
    return res;
}
int main(){
    cout<<trailingZero(15)<<endl;
    cout<<trailingZero2(20)<<endl;
    cout<<trailingZero3(100)<<endl;
    return 0;
}