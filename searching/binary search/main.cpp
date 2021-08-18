#include<bits/stdc++.h>
using namespace std;

//binary search iterative
int binary_search_iter(int a[], int n, int key){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] == key)
            return mid;
        else if(a[mid] > key){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

//binary search recursive
int binary_search_recur(int a[], int low, int high, int key){
    if(low>high)
        return -1;

    int mid = (high+low)/2;
    
    if(key == a[mid])
        return mid;
    else if(key > a[mid])
        return binary_search_recur(a,mid+1,high,key);
    else
        return binary_search_recur(a,low,mid-1,key);
}

//main function
int main(){
    int a[] = {1,2,3,4,5,6};
    int n = 6;
    int low = 0;
    int high = 5;
    int key = 10;
    cout << binary_search_iter(a,n,key)<<endl;
    cout << binary_search_recur(a,low,high,key);
    return 0;
}