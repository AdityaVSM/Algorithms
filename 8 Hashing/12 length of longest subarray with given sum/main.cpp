#include<bits/stdc++.h>
using namespace std;
/*
ex:a{5,8,-4,-4,9,-2,2} sum=0
two posible subarray with sum=0 : sa1{8,-4,-4},sa2{-2,2}
return max(len(sa1),len(sa2)) = len(sa1) = 3 
*/
int naive(vector<int> a, int given_sum){    //O(n*n)
    int n = a.size();
    int curr_max_len=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum==given_sum)
                curr_max_len = max(curr_max_len,(j-i)+1);
        }
    }
    return curr_max_len;
}

int efficient(vector<int> a, int given_sum){    //O(n) O(n)
    int n = a.size();
    int curr_max_len=0;
    unordered_map<int,int> map;
    int pref_sum=0;
    int res = 0;
    for(int i=0;i<n;i++){
        pref_sum += a[i];
        if(pref_sum==given_sum)
            res = i+1;
        if(!map.count(pref_sum))    //insert only if pref_sum does not exists in map as a key
            map.insert({pref_sum,i});
        if(map.count(pref_sum-given_sum))
            res = max(res, i-map[pref_sum-given_sum]);
    }
    return res;
}
int main(){
    vector<int> a{5,8,-4,-4,9,-2,2};
    int sum = 0;
    cout<<naive(a,sum)<<endl;
    cout<<efficient(a,sum)<<endl;
    return 0;
}