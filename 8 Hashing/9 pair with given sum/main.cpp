#include<bits/stdc++.h>
using namespace std;
/*
Given an array and sum check if any pair can result in that sum value
*/

int efficient(vector<int> a, int sum){
    int n = a.size();
    unordered_set<int> set;
    for(int i=0;i<n;i++){
        if(set.count(sum-a[i]))
            return true;
        set.insert(a[i]);
    }
    return -1;
}

int main(){
    vector<int> a = {1,2,8,9,10};
    int sum = 13;
    cout<<efficient(a,sum);
    return 0;
}