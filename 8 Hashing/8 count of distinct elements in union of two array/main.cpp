#include<bits/stdc++.h>
using namespace std;

int efficient(vector<int> a1, vector<int> a2){
    int n1 = a1.size();
    int n2 = a2.size();
    unordered_set<int> set;
    for(auto i : a1)
        set.insert(i);
    for(auto i : a2)
        set.insert(i);
    return set.size();
}
int main(){
    vector<int> a1 {10,10,20,30};
    vector<int> a2 {10,20,30,40};
    cout<<efficient(a1,a2);
    return 0;
}