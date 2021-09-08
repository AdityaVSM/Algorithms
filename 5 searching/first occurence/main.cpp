//return index of first occurence of a given element in a sorted array
#include<bits/stdc++.h>
using namespace std;

//recursive binary search [Time=O(logn) space=O(logn)]
int binary_search_recur(int a[], int n, int key, int low, int high){
    if(low > high) return -1;
    int mid = (low+high)/2;
    if(key > a[mid])
        return binary_search_recur(a,n,key,mid+1,high);
    else if(key < a[mid])
        return binary_search_recur(a,n,key,low,mid-1);
    else{
        if(mid==0 || a[mid-1]!=key)
            return mid;
        else 
            return binary_search_recur(a,n,key,low,mid-1);
    }
}

//iterative binary search [Time = O(logn) space=O(1)]
int binary_search_iter(int a[], int n, int key){
    int low=0,high=n-1;
    int res;
    while(high >= low){
        int mid = (high+low)/2;
        if(a[mid] == key){
            if(mid==0 || a[mid-1]!=key)
                return mid;
            else 
                high = mid-1;
        }
        else if(a[mid] > key){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}


int naive_search(int a[], int n, int key){ //O(n)
    for(int i=0;i<n;i++){
        if(a[i] == key)
            return i;
    }
    return -1;
}

int main(){
    int a[] = {1,10,10,10,20,20,40};
    int key = -1;
    int n = 7;
    cout<<naive_search(a,n,key)<<endl<<binary_search_iter(a,n,key)<<endl<<binary_search_recur(a,n,key,0,n-1);
    return 0;
}