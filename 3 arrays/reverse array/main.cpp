#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n){
    int high = n-1, low = 0;
    while(low < high){
        int temp = arr[low]; 
        arr[low] = arr[high];
        arr[high] = temp;
        high--;
        low++;
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    reverse(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}