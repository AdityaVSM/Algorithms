#include<bits/stdc++.h>
using namespace std;

/*
Given an array and index of pivot element place all the elements which are smaller than that element 
to left of that element and the rest to right
*/
int naive(int a[], int l, int h, int pivot){    //O(n) space and O(n) time
    int n = h-l+1, index=0;
    int temp[n];
    for(int i=l; i<=h; i++)
        if(a[i] < a[pivot])
            temp[index++] = a[i];
    for(int i=l; i<=h; i++)
        if(a[i] == a[pivot])
            temp[index++] = a[i];
    int res = l+index-1;
    for(int i=l; i<=h; i++)
        if(a[i] > a[pivot])
            temp[index++] = a[i];
    index = 0;
    for(int i=l; i<=h; i++)
        a[i] = temp[index++];
    return res;
}
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
void printArray(int a[], int n){
    for(int i=0; i<n; i++)
        cout << a[i] <<" ";
    cout<<"\n";
}
int main(){
    int a[] = {5,3,12,8,6};
    int n = sizeof(a)/sizeof(a[0]);
    int l=0,h=n-1;
    int pivot = 0;
    cout << lomutoPartition(a,l,h) << endl;
    printArray(a,n);
    return 0;
}