#include<bits/stdc++.h>
using namespace std;

void naive_selection_sort(int a[], int n){  //time = O(n*n) space = O(n) 
    int temp[n];
    for(int i=0; i<n; i++){
        int min_idx = 0;
        for(int j=1; j<n; j++)
            if(a[j] < a[min_idx])
                min_idx = j;
        temp[i] = a[min_idx];
        a[min_idx] = INT_MAX;
    }
    for(int i=0; i<n; i++)
        a[i] = temp[i];
}
void efficient_selection_sort(int a[], int n){  // time = O(n*n) space=O(1)
    for(int i=0; i<n; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++)
            if(a[j] < a[min_idx])
                min_idx = j;
        swap(a[min_idx], a[i]);
    }

}
void printArray(int a[], int n){
    for(int i=0; i<n; i++)
        cout << i << " ";
    cout<<"\n";
}
int main(){
    int a[] = {2,1,5,0};
    int n = 4;
    naive_selection_sort(a,n);
    printArray(a,n);

    int b[] = {2,1,5,0};
    efficient_selection_sort(b,n);
    printArray(a,n);
    return 0;
}