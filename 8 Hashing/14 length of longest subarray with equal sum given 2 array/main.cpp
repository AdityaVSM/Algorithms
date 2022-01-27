#include<bits/stdc++.h>
using namespace std;
int efficient(vector<int> a, vector<int> b){
    int n1 = a.size(), n2=b.size();
    int count=0;
    int temp[n1];
    for(int i=0;i<n1;i++){
        temp[i] = a[i]-b[i];      
    }
    unordered_map<int, int> ump;
    int sum = 0;
    for(int i = 0; i < n1; i++){
        sum += temp[i];
        if(sum == 0)
            count = i+1;
        if(ump.find(sum+n1) != ump.end()){
            if(count < i - ump[sum+n1])
                count = i - ump[sum+n1];
        }
        else ump[sum + n1] = i;
    }
    return count;
}
int main(){
    vector<int> a{0,1,0,0,0,0};
    vector<int> b{1,0,1,0,0,1};
    cout<<efficient(a,b)<<endl;
    return 0;
}