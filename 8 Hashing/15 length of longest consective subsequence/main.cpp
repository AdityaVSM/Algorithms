#include<bits/stdc++.h>
using namespace std;
/*
EX1. a{1,9,3,4,2,20}
        o/p = 4 (longest consective subsequence is 1,2,3,4)
EX2. a{10,20,30}
        o/p = 1 (longest consective subsequence is 10 or 20 or 30)
*/
int naive(vector<int> a){   //O(n*logn)
    int n = a.size();
    int res=1, curr=1;
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++){
        if(a[i] == a[i-1]+1)
            curr++;
        else if(a[i]!=a[i-1]){
            res = max(res,curr);
            curr=1;
        }
    }
    return max(curr,res);
}
int efficient(vector<int> a){   //O(n), O(n)
    int n = a.size(), res=1;
    unordered_set<int> set(a.begin(), a.end());
    for(auto x:set){
        if(!set.count(x-1)){
            int curr=1;
            while(set.count(x+curr))
                curr+;
            res = max(curr,res);
        }
    }    
    return res;
}
int main(){
    vector<int> a{1,9,3,4,2,20};
    cout<<naive(a)<<endl;
    return 0;
}