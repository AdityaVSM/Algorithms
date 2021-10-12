/*
Given an array of n ele where each ele represents number of chocoloates in a pack.
Distribute chocolate pack among m students in such a way that the diff between the pack containing
max and min number of chocolates is minimum.
return that min difference.
*/
#include<bits/stdc++.h>
using namespace std;

int chocolateDistribute(int a[], int n, int m){
    if(m>n)
        return -1;
    sort(a,a+n);
    int res = a[m-1] - a[0];
    for(int i=1; (i+m-1)<n; i++){
        res = min(res, a[i+m-1]-a[i]);
    }
    return res;
}
int main(){
    int a[] = {7,3,2,4,9,12,56};
    int n = 7,m=3;
    cout << chocolateDistribute(a,n,m) << endl;
    return 0;
}