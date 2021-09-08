/*
Given an array and integer sum find number of subsets of array whose sum is equal to given sum.
*/

#include<bits/stdc++.h>
using namespace std;

int subSetSum(int arr[], int n, int sum){
    if(n == 0) return (sum == 0)?1:0;
    return subSetSum(arr,n-1,sum) + subSetSum(arr,n-1,sum-arr[n-1]);
}
int main(){
    int arr[] = {10,5,2,3,6};
    int sum = 8;
    cout<<subSetSum(arr, 5, sum);
    return 0;
}