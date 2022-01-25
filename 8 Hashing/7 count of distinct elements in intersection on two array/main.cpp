#include<bits/stdc++.h>
using namespace std;
/*
Given two Unsorted arrays find number of distinct ele in intersection of those two array
ex: a1{30,15,20,5,13}
a2{30,5,30,80}
intersection{30,5}
res = 2
*/
int naive(vector<int> a1, vector<int> a2){  //O(n1*n2):time O(1):space
    int n1,n2;
    n1 = a1.size();
    n2 = a2.size();
    int count=0;
    for(int i=0;i<n1;i++){  //To check if a1[i] already exists in a1
        bool repeated = false;
        for(int j=0;j<i;j++)
            if(a1[j] == a1[i]){
                repeated = true;
                break;
            }
        if(repeated)    //If a[i] is repeated then continue
            continue;
        for(int j=0;j<n2;j++)   //To check if a1[i] exists in a2
            if(a1[i] == a2[j]){
                count++;
                break;
            }
    }
    return count;
}
int efficient(vector<int> a1, vector<int> a2){  //O(max(n1,n2)):time O(n1):space
    int n1,n2;
    n1 = a1.size();
    n2 = a2.size();
    int res =0;
    unordered_set<int> set;
    for(int i=0;i<n1;i++){
        set.insert(a1[i]);
    }
    for(auto i : a2){
        if(set.count(i)){
            res++;
            set.erase(i);
        }
    }
    
    return res;
}
int main(){
    vector<int> a1{30,15,20,5,13};
    vector<int> a2{30,5,30,80};
    cout<<naive(a1,a2)<<'\n';
    cout<<efficient(a1,a2)<<'\n';
    return 0;
}