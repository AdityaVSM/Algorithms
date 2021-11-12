#include<bits/stdc++.h>
using namespace std;
const int r =  4;
const int c = 4;
void normal_traversal(vector<vector<int>> mat){
    for(int i=0;i<mat.size();i++)
        for(int j=0; j<mat[i].size(); j++)
            cout<<mat[i][j]<< " ";
}

void border_traversal(vector<vector<int>> mat){
    if(mat.size()==1 /*or if r==1*/){  //only one row
        for(int i=0;i<mat[0].size();i++)
            cout<<mat[0][i]<<" ";
    }
    else if(c==1){  //only one column
        for(int i=0;i<c;i++)
            cout<<mat[i][0]<<" ";
    }
    else{
        for(int i=0;i<c;i++){
            cout<<mat[0][i] <<" ";
        }
        for(int i=1;i<r;i++){
            cout<<mat[i][c-1]<<" ";
        }
        for(int i=c-2;i>=0;i--){
            cout<<mat[r-1][i]<<" ";
        }
        for(int i=r-2;i>=1;i--){
            cout<<mat[i][0]<<" ";
        }
    }
}
int main(){
    int m,n=4;
    vector<vector<int>> mat = { {1,2,3,4},
                                {5,6,7,8},
                                {9,10,11,12},
                                {13,14,15,16}};
    // normal_traversal(mat);
    border_traversal(mat);
    return 0;
}