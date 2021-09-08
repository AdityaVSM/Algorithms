// Find missing string between two strings (only one character missing)

#include<bits/stdc++.h>
using namespace std;
char findTheDifference(string s, string t) {
    int sum = 0;
    for(int i = 0; i <t.length(); i++){
        sum = sum + ((int)t[i] - (int)s[i]);
    }
    return char(sum);
}

//Given an array nums containing n distinct numbers in the range [0, n], 
//return the only number in the range that is missing from the array. 
int missingNumber(vector<int>& nums) {
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 1; i <= nums.size();i++){
        sum1 = sum1 ^ i;
    }   
    for(int i = 0; i < nums.size();i++){
        sum2 = sum2 ^ nums[i];
    }   

    /*
    for(int i=1;i<=nums.size();i++){
            sum1 = sum1 ^ i;
            sum2 = sum2 ^ nums[i-1];      
    }
    */
    return sum1 ^ sum2;  

}
int main(){
    cout<<findTheDifference("abc","cbda")<<endl;
    cout<<findTheDifference("","a")<<endl;

    vector<int> arr = {3,0,1};
    cout<<missingNumber(arr)<<endl;
    return 0;
}