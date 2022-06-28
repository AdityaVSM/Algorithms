#include<bits/stdc++.h>
#include "../Helper/stack.h"
using namespace std;

//Naive n*n

//Efficient
vector<int> previous_greater(vector<int> nums){
    int n = nums.size();
    vector<int> res;
    MyStack<int> stack;
    res.push_back(-1);  //previous greater of first ele is -1
    stack.push(nums[0]);

    for(int i=1;i<n;i++){
        while(!stack.isEmpty() && stack.peek()<nums[i])     //pop until ele greater than nums[i] is found in stack
            stack.pop();
        if(stack.isEmpty())
            res.push_back(-1);
        else
            res.push_back(stack.peek());
        stack.push(nums[i]);
    }
    return res;
}
int main(){
    vector<int> nums {20,30,10,5,15};
    vector<int> res = previous_greater(nums);
    for(auto i : res)
        cout<<i<<" ";
    
    return 0;
}