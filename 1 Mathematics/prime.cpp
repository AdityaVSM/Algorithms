#include<bits/stdc++.h>
using namespace std;

bool isPrime1(int n){            // worst case-O(n) Best case-O(1) 
    if(n == 1)
        return false;
    for(int i=2; i<=n/2; i++){      
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

bool isPrime2(int n){               //worst case-O(sqrt(n))   best case- O(1)
    if(n == 1) return false;
    for(int i=2; i<=sqrt(n); i++){ 
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

bool isPrime3(int n){               //reduces time complexity by 3 times of above algorithm
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i=5; i*i<n; i+=6){
        if(n%i == 0 || n%(i+2) == 0){
            return false;
        }
    }
    return true;
}
int main(){
    cout<<isPrime1(5)<<endl;
    cout<<isPrime2(4)<<endl;
    cout<<isPrime3(13)<<endl;
    return 0;

}