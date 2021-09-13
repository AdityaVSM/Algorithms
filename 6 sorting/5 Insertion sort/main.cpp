#include<bits/stdc++.h>
using namespace std;
/*
best case = O(n) -> when arr is sorted
worst case = O(n*n) -> when arr is in reverse order
best algo when arr size is small
in-place
stable 👍
*/
void insertionSort(int a[], int n){ 
    for(int i=1; i<n; i++){
        int key = a[i];
        int j = i-1;
        while(j >= 0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main(){
    int a[] = {5,4,3,2,10};
    int n = 5;
    printArray(a,n);

    insertionSort(a,n);
    printArray(a,n);
    return 0;
}