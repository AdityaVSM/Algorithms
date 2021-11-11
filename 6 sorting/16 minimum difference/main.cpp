/*Given an array find the minimum difference between two ele in that arr*/
#include<bits/stdc++.h>
using namespace std;

int findMinNaive1(int a[], int n){    //O(n*n)
    int res = INT_MAX;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            res = min(res, abs(a[i]-a[j]));
        }
    }
    return res;
}

int findMinNaive2(int a[], int n){  //O(nlogn)
    int res = INT_MAX;
    sort(a,a+n);    //puts each element to it's closest value
    for(int i=0; i<n-1; i++){
        res = min(res, abs(a[i]-a[i+1]));
    }
    return res;
}

int main(){
    int n = 5;
    int a[] = {1,8,12,5,18};
    cout << findMinNaive1(a,n) << endl;
    cout << findMinNaive2(a,n) << endl;

    return 0;
}