#include<bits/stdc++.h>
using namespace std;

//NAIVE O(n*n)
int maxSum1(int arr[], int n){
    int res = arr[0];
    for(int i=0; i<n; i++){
        int curr = 0;
        for(int j=i; j<n; j++){
            curr += arr[j];
            res = max(res,curr);
        }
    }
    return res;
}

//theta(n)
int maxSum2(int arr[], int n){
    int res = arr[0];
    int maxEnding = arr[0];
    for(int i=0; i<n; i++){
        maxEnding = max(maxEnding + arr[i],arr[i]);
        res = max(res,maxEnding);
    }
    return res;
}

int main(){
    int arr[] = {-3,-1,-4};
    int n=3;
    cout << maxSum1(arr,n) << endl;
    cout << maxSum2(arr,n) << endl;
    return 0;
}