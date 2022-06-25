#include<bits/stdc++.h>
#include "../Helper/stack.h"
/*
Given an array of stock price in each day find span of days where stock increases in each day
ex:
i/p = [30,20,25,28,27,29]
o/p = [1 ,1, 2, 3, 1, 5]
*/
using namespace std;

//Naive
vector<int> stockSpanNaive(vector<int> stock_price){
    vector<int> span;
    for(int i=0;i<stock_price.size();i++){
        int span_count = 1;
        for(int j=i-1;j>0;j--){
            if(stock_price[j] < stock_price[i])
                span_count++;
            else
                break;
        }
        span.push_back(span_count);
    }
    return span;
}

/*
observatoin:
span = index_of_curr_ele - index_of_closese_largest_element_to_left_of_it

ex::
i/p = [30,     20,     25,     28,     27,     29]
o/p = [1(1-0) ,1(1-0), 2(2-0), 3(3-0), 1(4-3), 5(5-0)]
*/
vector<int> stockSpanEfficient(vector<int> stock_span){
    vector<int> span;
    MyStack<int> s;
    s.push(0);
    span.push_back(1);
    for(int i=1;i<stock_span.size();i++){
        while(!s.isEmpty() && stock_span[s.peek()]<=stock_span[i])
            s.pop();
        int curr_ele_span = s.isEmpty() ? i+1 : i-s.peek();
        span.push_back(curr_ele_span);
        s.push(i);
    }
    return span;
}

int main(){
    vector<int> stock_price {60, 10, 20, 40, 35, 30, 50, 70, 65};
    // vector<int> res = stockSpanNaive(stock_price);
    vector<int> res = stockSpanEfficient(stock_price);

    for(auto x: res){
        cout<<x<<" ";
    }
    return 0;
}