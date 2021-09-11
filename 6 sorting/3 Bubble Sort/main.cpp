#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int a[], int n){   //always O(n*n)
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

/*If array is already sorted in before n-1'th pass then remaining pass can be skipped */
void bubble_sort_efficient(int a[], int n){
    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0; j<n-i-1; j++)
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                swapped = true;
            }
        if(swapped == false)
            break;
    }
}
int main(){
    int a[] = {2,10,8,7};
    int n = 4;
    bubble_sort(a,n);
    for(auto i : a)
        cout << i << " ";

    //Efficient algorithm 
    int b[] = {2,10,8,7};
    bubble_sort_efficient(b,n);
    cout<<"\n";
    for(auto i : a)
        cout << i << " ";

    return 0;

}