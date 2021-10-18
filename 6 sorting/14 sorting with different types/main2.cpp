/*
Given an array with even and odd numbers. segregate odd and even numbers
ex: a[] = {12,54,6,8,5,7};
    o/p = {12,6,8,54,5,7}
*/

#include<bits/stdc++.h>
using namespace std;

void arrange(int a[], int n){   //O(n) time
    int currOdd = 0;
    for(int i=0; i<n; i++){
        if(a[i]%2==0){
            swap(a[currOdd++],a[i]);
        }
    }
}
void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] <<" ";
    }
    cout<<endl;
}
int main(){
    int n = 7;
    int a[] = {1,42,14,4,5,8,19};
    arrange(a,n);
    printArray(a,n);
    return 0;
}
