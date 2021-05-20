#include<bits/stdc++.h>
using namespace std;

//returns length of array after deletion
int deleteElement(int arr[], int n, int ele){
    int pos;
    for(int i=0;i<n;i++){
        if(arr[i] == ele){
            pos = arr[i];
            break;
        }
    }

    for(int i=pos-1;i<n;i++){
        arr[i] = arr[i+1];
    }

    return (n-1);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    n = deleteElement(arr,n,3);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}