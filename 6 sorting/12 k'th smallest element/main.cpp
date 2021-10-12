#include<bits/stdc++.h>
using namespace std;

/*return k'th smallest ele in an unsorted arr*/

int kthSmallest_naive(int a[], int n, int k){    //O(nlogn)
    sort(a,a+n);
    return a[k-1];
}

int lomuto_partition(int arr[], int l, int h){   
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}

int kthSmallest_efficient(int arr[],int n,int k){   //O(n*n) worst case but O(1) avg case
    int l=0,r=n-1;
    while(l<=r){
        int p=lomuto_partition(arr,l,r);
        if(p==k-1)
            return arr[p];
        else if(p>k-1)
            r=p-1;
        else
            l=p+1;
    }
    return -1;
}

int main(){
    int a[] = {12,3,10,34,41};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 3;
    // cout << kthSmallest_naive(a,n,k) << endl;
    cout << kthSmallest_efficient(a,n,k) << endl;
    return 0;
}