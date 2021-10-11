#include<bits/stdc++.h>
using namespace std;

int lomutoPartition(int arr[], int l, int h){   //Time O(n) space O(1)
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){   
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}

void quickSort_lomuto(int a[], int l, int h){
    if(l<h){
        int p = lomutoPartition(a,l,h);
        quickSort_lomuto(a,l,p-1);
        quickSort_lomuto(a,p+1,h);
    }
}

void printArray(int a[], int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout<<"\n";
}

int main(){
    int a[] = {25,5,12,56,2};
    int n = 5;
    printArray(a,n);
    quickSort_lomuto(a,0,n-1);
    printArray(a,n);
    return 0;
}