#include<bits/stdc++.h>
using namespace std;

void naive(vector<int> a){  //O(n*n) :time and O(1):space
    int n = a.size();
    for(int i=0;i<n;i++){
        bool exists = false;
        for(int j=0;j<i;j++)    //To avoid multiple printing of same element
            if(a[i] == a[j]){
                exists = true;
                break;
            }
        if(exists)
            continue;
        int count = 1;
        for(int j=i+1;j<n;j++)
            if(a[j] == a[i])
                count++;
        cout << a[i] <<" " << count <<endl;
    }
}

void efficient(vector<int> a){  //O(n) :time and O(n):time
    int n = a.size();
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        map[a[i]]++;
    }
    for(auto i : map){
        cout << i.first <<" " <<i.second<<endl;
    }
}

int main(){
    vector<int> a {1,2,3,2,2,3,4};
    // naive(a);
    efficient(a);
    return 0;
}