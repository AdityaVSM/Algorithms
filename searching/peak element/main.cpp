#include<bits/stdc++.h>
using namespace std;
int peak_ele_naive(int n, int a[]){ //O(n)
    if(a[0]>a[1])
        return a[0];
    if(a[n-1]>a[n-2])
        return a[n-1];
    for(int i=1;i<n-1;i++){
        if(a[i] >= a[i-1] && a[i]>=a[i+1])
            return a[i];
    }
    return -1;
}

int efficient_peak_ele(int n, int a[]){ //O(logn)
    int low = 0,high = n-1;
    while(low<=high){
        int mid = (high+low)/2;
        if((mid==0 || a[mid-1] <= a[mid]) &&(mid==n-1 || a[mid+1] <= a[mid]))
            return a[mid];
        if(mid > 0 && a[mid-1] >= a[mid])
            high = mid-1;
        else    
            low = mid+1;
    }
    return -1;
}
int main(){
    int a[] = {5,10,20,5,7};
    int n = 5;
    cout << peak_ele_naive(n,a)<<endl;
    cout << efficient_peak_ele(n,a)<<endl;
    return 0;
}