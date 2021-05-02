#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n == 2 || n==3) return true;
    if(n == 1 || n%2 == 0 || n%3 == 0) return false;
    for(int i=5; i*i<n; i+=6){
        if(n%i == 0 || n%(i+2) == 0) return false;
    }
    return true;
}
void primeFactors1(int n){               //O(n*sqrt(n)*logn)
    for(int i=2; i<n; i++){
        if(isPrime(i)){
            int x = i;
            while(n%x == 0){
                cout<<i<<" ";
                x *= i;
            }
        }
    }
}
void primeFactors2(int n){                 //O(sqrt(n)) --for prime numbers
    if(n<=1) return;
    while(n%2 == 0){
        cout<<2<<" ";
        n /= 2;
    }
    while(n%3 == 0){
        cout<<3<<" ";
        n/=3;
    }
    for(int i=5; i*i<n; i+=6){
        while(n%i == 0){
            cout<<i<<" ";
            n /= i;
        }
        while(n%(i+2) == 0){
            cout<<i+2<<" ";
            n /= (i+2);
        }
    }
    if(n>3){
        cout<<n<<" ";
    }
}
int main(){
    primeFactors1(12);
    cout<<endl;
    primeFactors2(15);
    return 0;
}