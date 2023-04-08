#include<bits/stdc++.h>
using namespace std;

//returns length of array after deletion
int deleteElement(int arr[], int n, int ele){
    int pos;
    for(int i=0;i<n;i++){
        if(arr[i] == ele){
            pos = i;
            break;
        }
    }
    

    for(int i=pos;i<n;i++){
        arr[i] = arr[i+1];
    }
    return n-1;
}

int main(){
    int arr[] = {14,25,31,44,5};
    int n = 5;
    n = deleteElement(arr,n,44);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}