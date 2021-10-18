/*
sort a binary array
ex: a[] = {0,0,1,1,0,1,0}
    o/p = {0,0,0,0,1,1,1}
*/

#include<bits/stdc++.h>
using namespace std;
void arrange(int a[], int n){
    int currOne = 0;
    for(int i=0; i<n; i++){
        if(a[i]==0)
            swap(a[currOne++],a[i]);
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
    int a[] = {0,0,1,1,0,1,0};
    arrange(a,n);
    printArray(a,n);
    return 0;
}