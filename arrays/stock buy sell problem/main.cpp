#include<bits/stdc++.h>
using namespace std;

//NAIVE
int maxProfit1(int arr[], int start, int end){
    if(end < start) return 0;
    int profit = 0;
    for(int i=start; i<end; i++)
        for(int j=i+1; j<=end; j++) 
            if(arr[j] > arr[i]){
                int curr_profit = arr[j]-arr[i] + maxProfit1(arr,start,i-1) + maxProfit1(arr,j+1,end);
                profit = max(profit,curr_profit);
            }
    return profit;
}

int maxProfit2(int arr[], int n){
    int profit = 0;
    for(int i=1; i<n; i++)
        if(arr[i] > arr[i-1])
            profit += (arr[i] - arr[i-1]); 
    return profit;        
}

int main(){
    int arr[] = {1,5,3,8,12};
    cout << maxProfit1(arr,0,4)<<endl;
    cout << maxProfit2(arr,5)<<endl;
    return 0;
}