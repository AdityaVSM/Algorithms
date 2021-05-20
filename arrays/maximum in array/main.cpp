#include<bits/stdc++.h>
using namespace std;

//Return largest element
int largest(int arr[], int n){
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}
int main(){
    int arr[] = {12,12,13,1,2,121};
    int n = 6;
    cout << largest(arr,n)<<endl;
    return 0;
}