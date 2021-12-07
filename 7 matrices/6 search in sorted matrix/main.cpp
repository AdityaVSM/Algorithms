#include<bits/stdc++.h>
using namespace std;
/*
Given a matrix which is row wise and column wise matrix 
find index of given element(if not present -1)

ex: for row wise and column wise sorted matrix{
    {10,20,30,40},
    {15,25,35,45},
    {27,39,37,48},
    {32,33,39,50}
}
*/

pair<int,int> naive_search(vector<vector<int>> &mat, int x){    //O(n*n) time and O(1) space
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            if(mat[i][j]==x)
                return make_pair(i,j);
        }
    }
    return make_pair(-1,-1);
}

/*
start from top right element
if(x==top_right) -> return
if(x<top_right) -> move left
if(x>top_right) -> move down
*/
pair<int,int> efficient_search(vector<vector<int>> &mat, int x){    //O(r+c) time
    int i=0,j=mat[0].size()-1;
    while(i<mat.size() && j>=0){
        if(mat[i][j]==x)
            return make_pair(i,j);
        else if(x > mat[i][j])
            i++;
        else
            j--;
    }
    return make_pair(-1,-1);
}

int main(){
    vector<vector<int>> mat {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };
    int ele = 39; 
    cout<<naive_search(mat,ele).first<<","<<naive_search(mat,ele).second<<"\n";
    cout<<efficient_search(mat,ele).first<<","<<efficient_search(mat,ele).second<<"\n";
    return 0;
}