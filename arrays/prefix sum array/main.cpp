#include<bits/stdc++.h>
using namespace std;

void generatePrefixSum(int p_sum[], int arr[], int n){
    p_sum[0] = arr[0];
    for(int i=1; i<n; i++){
        p_sum[i] = p_sum[i-1] + arr[i];
    }
}
void generateSuffixSum(int s_sum[], int arr[], int n){
    s_sum[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        s_sum[i] = s_sum[i+1] + arr[i];
    }
}

//Find sum from l to r indices(inclusive)
int findSum(int arr[], int n, int l, int r){
    int p_sum[n];
    generatePrefixSum(p_sum, arr, n);
    if(l == 0){
        return p_sum[r];
    }
    return p_sum[r]-p_sum[l-1];
}

//Find index of equilibrium point else -1 O(N) time ans O(N) space
int findEquilibrium(int arr[], int n){
    int s_sum[n];
    int p_sum[n];
    generateSuffixSum(s_sum,arr,n);
    generatePrefixSum(p_sum,arr,n);
    for(int i=0; i<n;i++){
        if(p_sum[i] == s_sum[i]){
            return i;
        }
    }
    return -1;
}

//O(n) time O(1) space
bool findEquilibrium2(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    int l_sum = 0;
    for(int i=0; i<n; i++){
        if(l_sum == (sum-arr[i]))
            return true;
        l_sum += arr[i];
        sum -= arr[i];
    }
    return false;
}
int main(){
    int arr[] = {2,8,3,9,6,5,4};
    int n = 7;
    cout << findSum(arr,n,0,2) << endl;
    cout << findSum(arr,n,1,3) << endl;
    cout << findSum(arr,n,2,6) << endl;
    int arr2[] = {3,4,8,-9,20,6};
    n = 6;
    cout << findEquilibrium(arr2,n) << endl;
    cout << findEquilibrium2(arr2,n) << endl;
    return 0;
}