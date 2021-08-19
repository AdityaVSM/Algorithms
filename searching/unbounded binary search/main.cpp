//Find a given element in an infinitely long array

#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[], int key, int low, int high){
    while(low <= high){
        int mid = (low+high) / 2;
        if(a[mid] == key)
            return mid;
        else if (a[mid] > key)
            high = mid-1;
        else 
            low = mid+1;
    }
    return -1;
}

int best_soln(int a[], int key){
    if(a[0] == key)
        return 0;
    int i=1;
    while(a[i] < key){
        i *= 2;
    }
    if(a[i] == key) return i;
    return binary_search(a,key,(i/2)+1,i-1);
}

int naive(int a[], int key){
    int i=0;
    while(true){
        if(a[i] == key) return i;
        if(a[i] > key) return -1;
        i++;
    }
    return -1;
}

int main(){
    int a[] = {1,13,19,122,224};
    int key = 13;
    cout<<naive(a,key)<<endl<<best_soln(a,key);
    return 0;
}