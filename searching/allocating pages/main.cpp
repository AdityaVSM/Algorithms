#include<bits/stdc++.h>
using namespace std;
/*
Minimize the number of pages read by any student
Only contiguous pages can be alloted 
each element in the array represents number of pages in that book
Allocate books to k number of students minimizing the maximum pages allocated
ex :
     a[] = {12,20,30,40}
     k = 2;
     ans = 60 (12+20+30=60 for one student and 40 for another student)
*/
//Naive recursive
int sum_range(int a[],int x, int y){
    int sum = 0;
    for(int i=x; i<=y; i++){
     sum += a[i];
    }
    return sum;
}
int naive_recur(int a[], int n, int k){
    if(k == 1)  return  sum_range(a,0,n-1);
    if(n == 1)  return a[0];
    int res = INT_MAX;
    for(int i=0; i<n; i++){
        res = min(res, max(naive_recur(a,i,k-1),  sum_range(a,i,n-1)));
    }
    return res;
}

int main(){
    int a[] = {10,20,30,40};
    int k = 2;
    int n = 4;
    cout << naive_recur(a,n,k) << endl;
    return 0;
}