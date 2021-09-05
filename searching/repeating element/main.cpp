/*
only one element is repeated
values of all the elements in the array range from 0 to n-1
*/
#include<bits/stdc++.h>
using namespace std;

int super_naive(int a[], int n){    //O(n*n) O(1)
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(a[i] == a[j])    return a[i];
    return -1;
}

int naive(int a[], int n){      //O(nlogn) O(1)
    sort(a,a+n);
    for(int i=0; i<n-1; i++)
        if(a[i] == a[i+1])  return a[i];
    return -1;
}

int efficient(int a[], int n){ 
    bool visited[n] = {false};
    for(int i=0; i<n; i++){
        if(visited[a[i]])
            return a[i];
        visited[a[i]] = true;
    }
    return -1;
}

int best(int a[], int n){//O(n) O(1)
    int slow = a[0]+1, fast = a[0]+1;
    do{
        slow = a[slow]+1;
        fast = a[a[fast] + 1] + 1;
    }while(slow!=fast);
    slow = a[0] + 1;
    while(slow != fast){
        fast = a[fast] + 1;
        slow = a[slow] + 1;
    }
    return slow-1;
}


int main(){
    int a[] = {0,1,3,4,2,2};
    int n = 6;
    cout<<super_naive(a,n)<<endl<<naive(a,n)<<endl<<efficient(a,n)<<endl<<best(a,n);
    return 0;
}