#include<bits/stdc++.h>
using namespace std;
 
// Returns the element that is repeated majority times in array
int majority(vector<int> arr){
    int n = arr.size();
    int majority = arr[0];
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == majority){
            count++;
        }else{
            count--;
            if(count == -1){
                majority = arr[i];
                count = 0;
            }
        }
    }
    //Checks if the element is repeated more than n/2 times

    count = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == majority)
            count++;
    }
    return count >= n/2 ? count : -1;
}

int main(){
    vector<int> arr = {2,2,3,1};
    cout<<majority(arr)<<endl;
    return 0;
}