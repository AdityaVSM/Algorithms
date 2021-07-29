#include<bits/stdc++.h>
using namespace std;

//majority = ouucrence of ele > n/2
//NAIVE O(n*n)
int majority(int arr[], int n){
    for(int i=0; i<n; i++){
        int count = 1;
        for(int j=i+1; j<n;j++){
            if(arr[i] == arr[j])
                count++;
        }
        return i;
    }
    return -1;
}

//Based on Moore's voting algorithm O(n)
int majority2(int arr[], int n){        //Might not return index of first occurence of majority ele
    int res=0, count=1;
    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1])
            count++;
        else
            count--;
        if(count == 0){
            res = i;
            count = 1;
        }
    }


    count = 0;
    for(int i=0; i<n; i++){
        if(arr[res] == arr[i])
            count++;
    }
    return res;
}

int main(){
    int arr[] = {8,3,4,8,8};
    int n = 5;
    cout << majority(arr,n) << endl;
    cout << majority2(arr,n) << endl;
    return 0;
}