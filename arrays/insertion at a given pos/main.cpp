#include<bits/stdc++.h>
using namespace std;

int insert(int arr[], int n, int size, int pos, int val){
    if(n == size){
        return n;
    }
    int index = pos-1;
    for(int i=n-1; i>=index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = val;
    return (n+1);
}

int main(){
    int arr[10] = {1,2,3,4};
    int pos = 3,val = 10;
    int n = insert(arr,4,10,pos,val);
    cout<<n<<endl;
    return 0;
}