#include<bits/stdc++.h>
using namespace std;

int gcd1(int a, int b){         //worst cse:O(min(a,b))
    int small = std::min(a,b);
    while(small > 0){
        if(a%small == 0 && b%small == 0){
            break;
        }
        small--;
    }
    return small;
}
//Euclid algo
int gcd2(int a, int b){         
    while(a != b){
        if(a>b)
            a -= b;
        else
            b -= a;
    }    
    return a;
}
//optimized Euclid aligo
int gcd3(int a, int b){     //Best approach O(log(min(a,b)))
    if(b == 0)
        return a;
    return gcd3(b,a%b);
}

int main(){
    cout<<gcd1(4,6)<<endl;
    cout<<gcd2(4,6)<<endl;
    cout<<gcd3(4,6)<<endl;
    return 0;
}