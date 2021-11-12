#include<bits/stdc++.h>
using namespace std;

/*
ip = {{1,2},
      {3,4},
      {5,6}}
op = 1,2,4,3,5,6
*/
void normal_traversal(int *mat[], int m, int n){
    for(int i=0;i<m;i++)
        for(int j=0; j<n; j++)
            cout<<mat[i][j]<< " ";
}

void snake_traversal(int *mat[], int m, int n){
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0; j<n; j++)
                cout << mat[i][j] <<" ";
        }else{
            for(int j=n-1; j>=0; j--)
                cout << mat[i][j] << " ";
        }
    }
}

int main(){
    int m=3,n=2;
    int *mat[m];
    for(int i=0;i<m;i++){
        mat[i] = new int[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0; j<n; j++){
            mat[i][j] = i+j;
        }
    }
    cout<<"Normal traversal :  "; 
    normal_traversal(mat,m,n);
    cout<<"\nSnake traversal : ";
    snake_traversal(mat, m, n);
    return 0;
}