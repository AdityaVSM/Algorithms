#include<bits/stdc++.h>
using namespace std;

//returns INDEX of second largest element else -1       O(n) TWO iterations
int secLargest(int arr[], int n){
    int max = 0;
    int secmax = -1;
    for(int i = 0; i <n;i++){
        if(arr[i] > arr[max]){
            max = i;
        }
    }
    for(int i=0; i<n;i++){
        if(arr[i] != arr[max]){
            if(secmax == -1){
                secmax = i;
            }else if(arr[i] > arr[secmax]){
                secmax = i;
            } 
        }
    }
    return secmax;
}

//returns INDEX of second largest element else -1       O(n) ONE iteration
int secLargest2(int arr[], int n){
    int max = 0;
    int secmax = -1;
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[max]){
            secmax = max;
            max = i;
        }
        else if(arr[i] != arr[max]){
            if(secmax == -1 || arr[secmax] < arr[i]){
                secmax = i;
            }
        }
    }
    return secmax;
}

int main(){
    int arr[] = {6,4};
    int n = 2;
    cout << secLargest(arr,n)<<endl; 
    cout << secLargest2(arr,n)<<endl;
    arr[1] = 6;
    cout << secLargest(arr,n)<<endl;
    cout << secLargest2(arr,n)<<endl;
    return 0;
}