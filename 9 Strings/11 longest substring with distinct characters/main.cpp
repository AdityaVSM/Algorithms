/*
substring - > should be contiguos
subsequence -> need not to be continguos but should be present in string
*/

#include<bits/stdc++.h>
using namespace std;

int naive(string &s){       //O(n*n)
    int n = s.length(), res=0;
    for(int i=0;i<n;i++){
        vector<bool> visited(256);
        for(int j=1;j<n;j++){
            if(visited[s[j]])
                break;
            else{
                res = max(res, i-j+1);
                visited[s[j]] = true;
            }
        }
    }
    return res;
}

int efficient(string &str){   //O(n)
    int n = str.length(); 
	int res = 0;
	vector<int> prev(256,-1);
	int i=0;
	for (int j = 0; j < n; j++){
	    i=max(i,prev[str[j]]+1);
	    int maxEnd=j-i+1;
	    res=max(res,maxEnd);
	    prev[str[j]]=j;
	} 
	return res;
}
int main(){
    string s = "aditya";
    cout<<efficient(s)<<endl;
    return 0;
}