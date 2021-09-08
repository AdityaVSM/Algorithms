#include<bits/stdc++.h>
using namespace std;

//NAIVE theta(n*n)
int maxDiff1(int arr[], int n){
    int res = arr[1] - arr[0];
    for(int i = 0; i <n;i++){
        for(int j=i+1; j<n; j++){
            res = max(res,arr[j]-arr[i]);
        }
    }
    return res;
}

//theta(n)
int maxDiff2(int arr[], int n){
    int res = arr[1] - arr[0];
    int minimum = arr[0];
    for(int j=0; j<n; j++){
        res = max(res, arr[j]-minimum);
        minimum = min(minimum,arr[j]);
    }
    return res;
}

int main(){
    int arr[] = {2,3,10,6,4,8,1};
    int n = 7;
    cout<<maxDiff1(arr,n)<<endl;
    cout<<maxDiff2(arr,n)<<endl;
    return 0;
}