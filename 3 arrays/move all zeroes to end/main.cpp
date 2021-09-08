#include<bits/stdc++.h>
using namespace std;

void moveZeroes(int arr[], int n){    //NAIVE time=O(n*n)
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            for(int j=i+1; j<n;j++){
                if(arr[j] != 0){
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
}

void moveZeroes2(int arr[], int n){  // O(n)
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

int main(){
    int arr[] = {8,5,0,0,10,0,12};
    int n = 7;
    moveZeroes(arr, n);
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int arr2[] = {8,5,0,0,10,0,12};
    moveZeroes2(arr2, n);
    for(int i=0; i<n;i++){
        cout<<arr2[i]<<" ";
    }
    return 0;
}