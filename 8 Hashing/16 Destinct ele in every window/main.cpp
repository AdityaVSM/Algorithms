#include<bits/stdc++.h>
using namespace std;
/*
Given an array and window size 
find number of distinct elements in every window of given size in the array
EX 1. a{10,20,20} window_size=2
o/p = 2,1 --> (10,20)->2 and(20,20)->1
*/
void naive(vector<int> arr, int k){ //O(n*n*n)
    int n = arr.size();
    for(int i=0;i<=n-k;i++){
        int count=0;
        for(int j=0;j<k;j++){
            bool flag=false;
            for(int p=0;p<j;p++){
                if(arr[i+j]==arr[i+p]){
                    flag=true;break;
                }
            }
            if(flag==false)
                count++;
        }
        cout<<count<<" ";
    }
}

void efficient(vector<int> arr, int k){ //O(n), O(n)
    int n = arr.size();
    map<int, int> m;    
    for (int i=0; i<k; i++){ 
        m[arr[i]] += 1; 
    } 
    cout << m.size() << " "; 
    for (int i = k; i < n; i++) { 
        m[arr[i - k]] -= 1;
        if (m[arr[i - k]] == 0) { 
            m.erase(arr[i-k]); 
        }   
        m[arr[i]] += 1; 
        cout << m.size() << " "; 
    } 
}
int main(){
    vector<int> a{10,20,20};
    // naive(a,2);
    efficient(a,2);
    return 0;
}