/*
sort an array containing 0,1 and 2
*/
#include<bits/stdc++.h>
using namespace std;

void arrange(int a[], int n){       //O(n) time
    int low,mid = 0, high = n-1;
    while(mid <= high){
        if(a[mid] == 0)
            swap(a[low++], a[mid++]);
        else if(a[mid] == 1)
            mid++;
        else
            swap(a[mid], a[high--]);
    }
}
void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] <<" ";
    }
    cout<<endl;
}
int main(){
    int n=7;
    int a[] = {1,2,0,0,1,2,1};
    arrange(a,n);
    printArray(a,n);
    return 0;
}