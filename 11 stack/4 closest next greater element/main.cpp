#include<bits/stdc++.h>
#include "../Helper/stack.h"
using namespace std;

vector<int> next_greater(vector<int> nums){
    int n = nums.size();
    vector<int> res;
    MyStack<int> stack;
    res.push_back(-1);  //previous greater of first ele is -1
    stack.push(nums[n-1]);

    for(int i=n-2;i>=0;i--){
        while(!stack.isEmpty() && stack.peek()<nums[i])
            stack.pop();
        if(stack.isEmpty())
            res.push_back(-1);
        else
            res.push_back(stack.peek());
        stack.push(nums[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    vector<int> nums {20,30,10,5,15};
    vector<int> res = next_greater(nums);
    for(auto i : res)
        cout<<i<<" ";
    
    return 0;
}