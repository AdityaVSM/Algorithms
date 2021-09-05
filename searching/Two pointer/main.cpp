//Given an unsorted array and an element x find if  there is a pair with sum equal to x in that array

#include<bits/stdc++.h>
using namespace std;
bool naive(int a[], int n, int key){    //O(n*n)
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(a[i]+a[j]==key)
                return true;
        }
    }
    return false;
}
bool two_pointer(int a[], int n, int key){  //O(n) only works in sorted array
    int left = 0, right = n-1;
    while(left<right){
        int sum = a[left]+a[right];
        if(sum == key)  return true;
        if(sum > key)   right--;
        if(sum < key)   left++;
    }
    return false;
}
int main(){
    int a[] = {3,5,9,2,8,10,11};
    int key = 17;
    int n = 7;
    cout<<naive(a,n,key)<<endl;
    int b[] = {1,2,3,4,5,6};
    n = 6;
    key = 22;
    cout<<two_pointer(b,n,key)<<endl;
    return 0;
}