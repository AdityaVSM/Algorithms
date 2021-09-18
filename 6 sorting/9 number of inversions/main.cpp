#include<bits/stdc++.h>
using namespace std;

/*
inversion happens when an element is larger than right element
ex: a[] = {2,4,1,3,5}
inversion = {(4,1), (4,3), (2,1)} total of 3 inversions
*/

int naive(int a[], int n){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j])
                count++;
        }
    }
    return count;
}

int mergeAndSort(int a[], int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    int left[n1],right[n2];
    for(int i=0; i<n1; i++){
        left[i] = a[l+i];
    }
    for(int i=0; i<n2; i++){
        right[i] = a[m+1+i];
    }
    int res=0,i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            a[k++] = left[i++];
        }else{
            a[k++] = right[j++];
            res += (n1-i);
        }
    }
    while(i<n1){
        a[k++] = left[i++];
    }
    while(j<n2){
        a[k++] = right[j++];
    }
    return res;
}

int efficient(int a[], int l, int r){
    int res = 0;
    if(l<r){
        int m = (l+r)/2;
        res += efficient(a,l,m);
        res += efficient(a,m+1,r);
        res += mergeAndSort(a,l,m,r);
    }
    return res;
}


int main(){
    int a[] = {2,4,1,3,5};
    int n = 5;
    cout << naive(a,n) << "\n";
    cout << efficient(a,0,n-1) << "\n";
    return 0;
}