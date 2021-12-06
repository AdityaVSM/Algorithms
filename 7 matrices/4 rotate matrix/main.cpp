#include<bits/stdc++.h>
using namespace std;
/*
Rotate matrix anti-clock wise by 90
ex: {
    {1,2,3},
    {4,5,6},
    {7,8,9}
}
becomes: {
    {3,6,9},
    {2,5,8},
    {1,4,7}
}
*/
void display(vector<vector<int>> &mat,int n){
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++)
            cout<<mat[i][j]<< " ";
        cout<<"\n";
    }
}

void naive_rotate(vector<vector<int>> &mat, int n){   //O(n*n) and O(n*n)
    vector<vector<int>> temp = mat;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[n-j-1][i] = mat[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = temp[i][j];
        }
    }
}


//Find transpose and swap rows

void transpose(vector<vector<int>>& mat, int n){//O(n*n) time and O(1) space
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            swap(mat[i][j], mat[j][i]);
    }
}
void efficient_rotate(vector<vector<int>> &mat, int n){     //O(n*n) time and O(n) space
    transpose(mat,n);
    for(int i=0;i<n;i++){
        int low = 0, high=n-1;
        while(low<high){
            swap(mat[low][i], mat[high][i]);
            low++;
            high--;
        }
    }
}

int main(){
    vector<vector<int>> mat  
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int n=3;
    display(mat,n);
    cout<<"After rotation: \n";
    // naive_rotate(mat,n);
    efficient_rotate(mat,n);
    display(mat,n);
    return 0;
}