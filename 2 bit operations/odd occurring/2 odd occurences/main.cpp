#include<bits/stdc++.h>
using namespace std;

void twoOddOccurences(int a[],int n){
    int exor=0,res1=0,res2=0;
    for(int i=0;i<n;i++)
        exor = exor ^ a[i];
    int sn = exor & ~(exor - 1);
    for(int i=0;i<n;i++){
        if((a[i] & sn) != 0)    
            res1 = res1 ^ a[i];
        else
            res2 = res2 ^ a[i];
    }
    cout<<res1<<" "<<res2<<endl;
}

int main(){
    int a[] = {3,4,3,4,5,4,4,6,7,7};
    int n = 10;
    twoOddOccurences(a,n);
    return 0;
}