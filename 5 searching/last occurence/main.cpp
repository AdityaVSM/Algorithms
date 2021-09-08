//Find index of last occurence of a given element in a sorted array


#include<bits/stdc++.h>
using namespace std;

int binary_search_recur(int a[], int n, int key, int low, int high){
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(a[mid] > key)
        return binary_search_recur(a,n,key,low,mid-1);
    else if(a[mid] < key)
        return binary_search_recur(a,n,key,mid+1,high);
    else{
        if(mid==n-1 || a[mid+1] != key)
            return mid;
        else   
            return binary_search_recur(a,n,key,mid+1,high);
    }
}


//iterative binary search [Time=O(logn) space=O(1)]
int binary_search_iter(int a[], int n, int key){
    int low = 0, high = n-1;
    while (low<=high){
        int mid = (low+high)/2;
        if(a[mid] < key)
            low = mid+1;
        else if(a[mid] > key)
            high = mid-1;
        else{
            if(mid == n-1 || a[mid+1] != key)
                return mid;
            else    
                low = mid+1;
        }
    }
    return -1;    
}

int naive_search(int a[], int n, int key){  //O(n time)
    for(int i=n-1;i>=0;i--){
        if(a[i] == key)
            return i;
    }
    return -1;
}

int main(){
    int a[] = {1,10,10,10,20,20,40};
    int key = 10;
    int n = 7;
    cout<<naive_search(a,n,key)<<endl<<binary_search_iter(a,n,key)<<endl<<binary_search_recur(a,n,key,0,n-1)<<endl;
    return 0;
}