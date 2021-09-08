#include<bits/stdc++.h>
using namespace std;

//NAIVE theta(n*n)
int trap1(int arr[], int n){
    int res = 0;
    for(int i=1; i<n-1; i++){
        int lmax = arr[i];
        for(int j=0; j<i; j++)
            lmax = max(lmax,arr[j]);
        int rmax = arr[i];
        for(int j=i+1; j<n; j++)
            rmax = max(rmax,arr[j]);
        res += (min(rmax,lmax) - arr[i]);
    }
    return res;
}

//O(n)
int trap2(int arr[], int n){
    int res = 0;
    int lmax[n],rmax[n];
    lmax[0] = arr[0];
    for(int i=0; i<n; i++)
        lmax[i] = max(lmax[i-1],arr[i]);

    rmax[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--)
        rmax[i] = max(rmax[i+1], arr[i]);
    
    for(int i=1; i<n-1; i++)
        res += (min(lmax[i],rmax[i]) - arr[i]);

    return res;
}
int main(){
    int arr[] = {3,0,1,2,5};
    int n = 5;
    cout << trap1(arr,n)<<endl;
    cout << trap2(arr,n)<<endl;
    return 0;
}