#include<bits/stdc++.h>
using namespace std;

// returns length of final array

int remove(int arr[], int n){  //Naive approach time = theta(n) space = O(n)
    int temp[n];
    temp[0] = arr[0];
    int res = 1;
    for(int i=1; i<n; i++){
        if(arr[i] != temp[res-1]){
            temp[res] = arr[i];
            res++;
        }
    }
    for(int i=0; i<n; i++){
        arr[i] = temp[i];
    }
    return res;
}

int remove2(int arr[], int n){      //time=theta(n) space O(1)
    int res = 1;
    for(int i=0; i<n; i++){
        if(arr[i] != arr[res-1]){
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}

int main(){
    int arr[] = {1,2,2,3,4,5,5,5};
    int n = 8;
    n = remove(arr,n);
    cout<<n<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    n = remove2(arr,n);
    cout<<"\n"<<n<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}