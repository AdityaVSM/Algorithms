//Find the count of occurences of a given element in a sorted array

#include<bits/stdc++.h>
using namespace std;

int first_occurence(int a[], int n, int key){
    int low=0,high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(key < a[mid])
            high = mid-1;
        else if(key > a[mid])
            low = mid+1;
        else{
            if(mid==0 || a[mid-1]!=key)
                return mid;
            else    
                high = mid-1;
        }
    }
    return -1;
}

int last_occurence(int a[], int n, int key){
    int low=0,high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(key < a[mid])
            high = mid-1;
        else if (key > a[mid])
            low = mid+1;
        else{
            if(mid==n-1 || a[mid+1] != key)
                return mid;
            else    
                low = mid+1;
        }
    }
    return -1;
}

int best_soln(int a[], int n, int key){ //O(logn)
    int first = first_occurence(a,n,key);
    if(first == -1)
        return -1;
    else
        return last_occurence(a,n,key) - first + 1;
}

int naive(int a[], int n, int key){     //O(n) time
    int count = 0;
    for(int i=0;i<n;i++){
        if(a[i] == key){
            count++;
        }
    }
    return count;
}

int main(){
    int a[] = {1,13,13,13,24};
    int n = 5;
    int key = 13;
    cout<<naive(a,n,key)<<endl<<best_soln(a,n,key)<<endl;
    return 0;
}