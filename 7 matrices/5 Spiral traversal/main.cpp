#include<bits/stdc++.h>
using namespace std;
/*
ex: {
    {1,2,3},
    {4,5,6},
    {7,8,9}
}
becomes: 1,2,3,6,9,8,7,4,5
*/

void display(vector<vector<int>> mat){
    for(int i=0;i<mat.size();i++)
        for(int j=0; j<mat[i].size(); j++)
            cout<<mat[i][j]<< " ";
}

void spiral_traversal(vector<vector<int>>& mat){    //O(r*c) time O(1) space
    int top,left=0;
    int bottom=mat.size()-1, right=mat[0].size()-1;
    while(bottom>=top && right>=left){
        for(int i=left;i<=right;i++)    //top row
            cout<<mat[top][i]<<" ";
        top++;

        for(int i=top;i<=bottom;i++)  //rightmost column
            cout<<mat[i][right]<<" ";
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--)   //bottom row reverse order
                cout<<mat[bottom][i]<<" ";
            bottom--;
        }

        if(left<=right){
            for(int i=bottom;i>=top;i--){     //leftmost column reverse order
                cout<<mat[i][left]<<" ";
            }
            left++;
        }        
    }
}
int main(){
    vector<vector<int>> mat {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    spiral_traversal(mat);

    return 0;
}