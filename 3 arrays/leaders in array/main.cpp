#include<bits/stdc++.h>
using namespace std;

//An element is called leader if there is no element greater than that towards right of it

//NAIVE O(n*n)
vector<int> leader(int arr[], int n){
    vector<int> res;
    for(int i=0; i<n; i++){
        bool flag = true;
        for(int j=i+1; j<n; j++){
            if(arr[j] >= arr[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            res.push_back(arr[i]);
        }
    }
    return res;
}

//theta(N)
vector<int> leader2(int arr[], int n){
    vector<int> res;
    
    int curr_leader = arr[n-1];
    res.push_back(curr_leader);

    for(int i=n-2; i>=0; i--){
        if(arr[i] > curr_leader){
            curr_leader = arr[i];
            res.push_back(curr_leader);
        }
    }
    return res;
}

int main(){
    int arr[] = {7,10,4,10,6,5,2};
    int n = 7;
    // vector<int> res = leader(arr,n);
    // for(int i=0; i<res.size(); i++){
    //     cout<<res[i]<<" ";
    // }

    vector<int> res = leader2(arr,n);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}