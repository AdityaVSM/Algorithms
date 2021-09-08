#include<bits/stdc++.h>
using namespace std;

int oddOccurence1(int a[], int n){
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(a[i] == a[j])
                count++;  
        }
        if(count % 2 != 0)
            return a[i];
    }
    return -1;
}

int oddOccurence2(int a[], int n){
    int res = 0;
    for(int i=0;i<n;i++)
        res = res ^ a[i];
    return res;
}

int main(){
    int a[] = {1,22,3,3,22};
    cout<<oddOccurence1(a, 5)<<" "<<oddOccurence2(a,5);
    return 0;
}