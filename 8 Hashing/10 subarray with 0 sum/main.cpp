#include<bits/stdc++.h>
using namespace std;
/*
Check if any subarray exists with sum=0
*/
bool naive(vector<int> a){  //O(n*n) : time
    int n = a.size();
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += a[j];
            if(sum == 0)
                return true;
        }
    }
    return false;
}
//Using prefix sum and hash_set
bool efficient(vector<int> a){  //O(n):time  O(n):space
    int n = a.size();
    unordered_set<int> set;
    int prefix_sum = 0;
    for(int i=0;i<n;i++){
        prefix_sum += a[i];
        if(set.count(prefix_sum))
            return true;
        if(prefix_sum==0)
            return true;
        set.insert(prefix_sum);
    }
    return false;
}
int main(){
    vector<int> a{1,4,13,3,-10,5};
    cout<<naive(a)<<endl;
    cout<<efficient(a)<<endl;
    return 0;
}