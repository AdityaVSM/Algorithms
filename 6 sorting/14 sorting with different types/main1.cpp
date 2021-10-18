/*
Given an array with +ve and -ve elements.  segregate those elements
order of each group can be anything
ex: a[] = {15, -3, -2, 18};
    o/p = {-3, -2, 15, 18};
*/
#include<bits/stdc++.h>
using namespace std;

void arrange(int a[], int n){   //O(n) time
    int currPos = 0;
    for(int i=0;i<n;i++){
        if(a[i] <0){
            swap(a[currPos], a[i]);
            currPos++;
        }
    }
}
void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout<<endl;
}
int main(){
    int n = 6;
    int a[] = {-1,-3,4,6,-2,18};
    arrange(a,n);
    printArray(a,n);
    return 0;
}