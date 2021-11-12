#include<bits/stdc++.h>
using namespace std;

/*
Given arrival and departure timings find maximum number of people that we can meet
in the party once we go to party in a certain time interval
*/
int efficient(int arrival[], int departure[], int n){ //O(nlogn)
    sort(arrival, arrival+n);
    sort(departure, departure+n);

    int i=1,j=0,res=1,curr=1;
    while(i<n && j<n){
        if(arrival[i] <= departure[j]){
            curr++;
            i++;
        }
        else{
            curr--;
            j++;
        }
        res = max(res,curr);
    }
    return res;
}
int main(){
    int arr[] = {900, 600, 700};
    int depart[] = {1000, 800, 730};
    int n = 3;
    cout << efficient(arr,depart,n);
    return 0;
}