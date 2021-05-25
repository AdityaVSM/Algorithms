#include<bits/stdc++.h>
using namespace std;

//NAIVE O(n*n)
int maxSum1(int arr[], int n){
    int res = 1;
    for(int i=0; i<n; i++){
        int curr = 1;
        for(int j=i+1; j<n; j++){
            if(arr[j]%2==0 && arr[j-1]%2!=0  ||  arr[j]%2!=0 && arr[j-1]%2==0)
                curr++;
            else
                break;
        }
        res = max(res,curr);
    }
    return res;
}

//based on KADANE's algo O(n)
int maxSum2(int arr[], int n){
    int res=1,curr=1;
    for(int i=0; i<n; i++){
        if(arr[i]%2==0 && arr[i-1]%2!=0  ||  arr[i]%2!=0 && arr[i-1]%2==0){
            curr++;
            res = max(res,curr); //extend same subarray
        }else{
            curr=1;  //start new subarry(start count from 1)
        }
    }
    return res;
}

int main(){
    int arr[] = {10,12,14,7,8};
    int n = 5;
    cout << maxSum1(arr,n) <<endl;
    cout << maxSum2(arr,n) <<endl;
    return 0;
}