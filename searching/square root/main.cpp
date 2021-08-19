//Find square root of a number if it is a perfect square else return floor of square root found

#include<bits/stdc++.h>
using namespace std;

int bin_search_sqrt(int n){     //O(logn)
    int low = 0,high = n;
    int ans = 0;
    while(low <= high){
        int mid = (low+high)/2;
        if(mid*mid == n)
            return mid;
        else if(mid*mid > n)
            high = mid-1;
        else{
            low = mid+1;
            ans = mid;
        }
    }
    return ans;
}

int naive_sqroot(int n){    //O(sqrt(n))
    int i=1;
    while(i*i <= n)
        i++;
    return (i-1);
}

int main(){
    cout<<naive_sqroot(5)<<endl<<bin_search_sqrt(56)<<endl;
    return 0;
}