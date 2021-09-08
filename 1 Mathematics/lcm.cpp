#include <bits/stdc++.h>
using namespace std;

int lcm1(int a, int b){      //O(a*b)
    int big = std::max(a,b);
    while(true){
        if(big%a == 0 && big%b == 0){
            break;
        }
        big++;
    }
    return big;
}

int gcd1(int a, int b){ 
    if(b == 0){
        return a;
    }
    return gcd1(b,a%b);
}
int lcm2(int a, int b){     //Best case O(log(min(a,b)))
    int gcd = gcd1(a,b);
    return (a*b)/gcd;
}

int main(){
    cout<<lcm1(2,5)<<endl;
    cout<<lcm2(2,4)<<endl;
    return 0;
}