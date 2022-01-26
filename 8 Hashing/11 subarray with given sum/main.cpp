#include<bits/stdc++.h>
using namespace std;

//Using prefix sum and Hash_set
bool efficient(vector<int> a, int sum){
    int n = a.size();
    unordered_set<int> set;
    int prefix_sum = 0;
    for(int i=0;i<n;i++){
        prefix_sum += a[i];
        if(set.count(prefix_sum-sum))
            return true;
        if(prefix_sum==sum)
            return true;
        set.insert(prefix_sum);
    }
    return false;
}

int main(){
    vector<int> a{1,4,13,3,-10,5};
    cout<<efficient(a,16);
    return 0;
}