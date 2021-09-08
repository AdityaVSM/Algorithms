#include<bits/stdc++.h>
using namespace std;

int findMissing(int a[], int n){
    int res1 = 0;
    for(int i=0; i<n; i++){
        res1 = res1^a[i];
    }
    int res2 = 0;
    for(int i=1; i<=n+1; i++){
        res2 = res2^i;
    }
    return res1^res2;
}
int main(){
    int a[] = {1,3,4,5};
    cout<<findMissing(a,4)<<" ";
    return 0;
}