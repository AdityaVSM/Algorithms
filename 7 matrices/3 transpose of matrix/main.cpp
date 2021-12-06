#include<bits/stdc++.h>
using namespace std;
/*row => columns
move elements at (i,j) to (j,i)
*/

void display(vector<vector<int>> &mat,int n){
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++)
            cout<<mat[i][j]<< " ";
        cout<<"\n";
    }
}

void naive(vector<vector<int>>& mat, int n){    //O(n*n) time and O(n*n) space
    vector<vector<int>> temp = mat;     //always initialize before accessing elemnts line(19) temp[i][j] not present if temp is not initialized with mat
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            temp[i][j] = mat[j][i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            mat[i][j] = temp[i][j];
    }
}

void efficient(vector<vector<int>>& mat, int n){//O(n*n) time and O(1) space
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            swap(mat[i][j], mat[j][i]);
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
    cout<<"After transpose: \n";
    // naive(mat,n);
    efficient(mat,n);
    display(mat,n);
    
    return 0;
}