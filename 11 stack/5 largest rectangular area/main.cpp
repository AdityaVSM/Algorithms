#include<bits/stdc++.h>
#include "../Helper/stack.h"

/*
Given an array of heights of rectangular histogram
find max height of rectangle that can be formed by combining 2 or more elements in array

ex: {6,2,5,4,1,5,6}
o/p : largest rectangle can be obtained by combining 5 with 6

imagine as histogram and combine 5 and upto 5 in 6 => area = 10 (5*2)
*/
using namespace std;

//Naive O(n^2)
int get_max_area_naive(vector<int> area){
    int max_area = 0;
    int n = area.size();
    for(int i=0; i<n; i++){
        int curr_area = area[i];
        for(int j=i+1; j<n;j++){
            if(area[j] < area[i])
                break;
            else
                curr_area += area[i];
        }
        for(int j=i-1; j>=0; j--){
            if(area[j] < area[i])
                break;
            else
                curr_area += area[i];
        }
        max_area = max(max_area, curr_area);
    }
    return max_area;
}

//Efficient O(n)
vector<int> get_next_smaller(vector<int> area, int n){
    vector<int> res;
    MyStack<int> stack;
    res.push_back(n);
    stack.push(n-1);

    for(int i=n-2;i>=0;i--){
        while(!stack.isEmpty() && area[i]<area[stack.peek()])
            stack.pop();
        if(stack.isEmpty())
            res.push_back(n);
        else
            res.push_back(stack.peek());
        stack.push(i);
    }

    reverse(res.begin(), res.end());
    return res;
}
vector<int> get_prev_smaller(vector<int> area, int n){
    vector<int> res;
    MyStack<int> stack;
    res.push_back(-1);
    stack.push(0);

    for(int i=1;i<n;i++){
        while(!stack.isEmpty() && area[i]<area[stack.peek()])
            stack.pop();
        if(stack.isEmpty())
            res.push_back(-1);
        else
            res.push_back(stack.peek());
        stack.push(i);
    }

    return res;
}
int get_max_area_efficient(vector<int> area, int n){
    int res = 0;
    vector<int> next_smaller = get_next_smaller(area,n);
    vector<int> prev_smaller = get_prev_smaller(area,n);

    for(int i=0;i<n;i++){
        int curr_max_area = area[i];
        curr_max_area += area[i] * (next_smaller[i] - i - 1);
        curr_max_area += area[i] * (i - prev_smaller[i] - 1);
        res = max(res, curr_max_area);
    }
    return res;
}

int main(){
    vector<int> area {6,2,5,4,1,5,6};
    cout << get_max_area_naive(area)<<endl;
    cout << get_max_area_efficient(area, area.size())<<endl;

    return 0;
}