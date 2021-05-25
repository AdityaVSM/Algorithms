#include<bits/stdc++.h>
using namespace std;

//NAIVE worst case when all elements are 1 O(n*n)
int max1(int arr[], int n){
    int res=0;
    for(int i=0; i<n; i++){
        int curr=0;
        for(int j=i; j<n; j++){
            if(arr[j] == 1)
                curr++;
            else
                break;
        }
        res = max(res,curr);
    }
    return res;
}

//theta(n)
int max2(int arr[], int n){
    int res=0,count=0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0) 
            count=0;
        else
            count++;  
        res = max(res,count);
    }
    return res;
}

int main(){
    int arr[] = {0,1,1,1,0,1};
    int n = 6;
    cout << max1(arr,n) <<endl;
    cout << max2(arr,n) <<endl;
    return 0;
}