#include<bits/stdc++.h>
using namespace std;

/*
Given an array and index of pivot element place all the elements which are smaller than that element 
to left of that element and the rest to right
*/
int naive(int a[], int l, int h, int pivot){
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
void printArray(int a[], int n){
    for(int i=0; i<n; i++)
        cout << a[i] <<" ";
    cout<<"\n";
}
int main(){
    int a[] = {5,3,12,8,5};
    int n = sizeof(a)/sizeof(a[0]);
    int l=0,h=n-1;
    int pivot = 0;
    cout << naive(a,l,h,pivot) << endl;
    printArray(a,n);
    return 0;
}