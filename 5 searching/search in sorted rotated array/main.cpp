/*
Sorted rotated array = sorted array is rotated (clock/counter clock) n times (n>=0)
*/
#include<bits/stdc++.h>
using namespace std;
//Naive linear search

//Binary search  O(logn)
int bin_search(int n, int a[], int key){
    int low = 0,high = n-1;
    while(low<=high){
        int mid = (high+low)/2;
        if(a[mid] == key)
            return mid;
        else if(a[mid] > a[low]){
            //left half is sorted
            if(key>=a[low] && key<a[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else{
            //Right half can be sorted or not
            if(key>a[mid] && key<=a[high])
                low = mid+1;
            else    
                high = mid-1;
        }
    }
    return -1;
}
int main(){
    int a[] = {100,200,500,1000,2000,10,20};
    int n = 7;
    int key = 10;
    cout<<bin_search(n,a,key);
    return 0;
}