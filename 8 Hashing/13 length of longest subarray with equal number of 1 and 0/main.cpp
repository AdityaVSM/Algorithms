#include<bits/stdc++.h>
using namespace std;
/*
1. a{1,0,1,1,1,0,0}
    o/p = 6(index 1-last)
2. a{1,1,1,1}
    o/p = 0    
*/
int naive(vector<int> a){   //O(n*n)
    int n = a.size();
    int res=0;
    for(int i=0;i<n;i++){
        int count0=0,count1=0;
        for(int j=i;j<n;j++){
            if(a[j]==0)
                count0++;
            else
                count1++;
            if(count0==count1)
                res = max(res,count0+count1);
        }
        
    }
    return res;
}

int efficient(vector<int> arr){
    int n = arr.size();
    for(int i = 0; i < n; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;
     
    unordered_map<int, int> ump;
    int sum = 0, maxLen = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == 0)
         maxLen = i+1;
         
        if(ump.find(sum+n) != ump.end()){
            if(maxLen < i - ump[sum+n])
             maxLen = i - ump[sum+n];
        }
        else ump[sum + n] = i;
    }
    
    return maxLen;
}
int main(){
    vector<int> a{1,0,1,1,1,0,0};
    cout<<naive(a)<<endl;
    cout<<efficient(a)<<endl;
    return 0;
}