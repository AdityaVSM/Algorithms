#include<bits/stdc++.h>
using namespace std;
/*
* used to store key-value pair
* unordered maps are implemented using hashing
* elements are arranged internally in any random order
* Repetitive elements can be stored

set.begin() ->  O(1)   in worst case
set.end() ->    O(1)   in worst case
set.size() ->   O(1)   in worst case
set.empty() ->  O(1)   in worst case

set.erase(it) ->    O(1) on average
set.count() ->      O(1) on average
set.find() ->       O(1) on average
set.insert() ->     O(1) on average
[] ->               O(1) on average
at ->               O(1) on average
*/

int main(){

    unordered_map<string, int> m;
    m["India"] = 1;
    m["UK"] = 24;
    m["NZ"] = 13;
    m.insert({"US",10});

    for (auto it:m)
        cout<<"{"<<it.first<<","<<it.second<<"} ";

    //find function return address if exists else it returns m.end()
    //can also be used to find value of that key
    if(m.find("Srilanka")!=m.end())
        cout<<"\nSrilanka exists";
    else
        cout<<"\nSrilanka doesn't exists in map";
    
    auto it1 = m.find("UK");
    if(it1!=m.end())
        cout<<"\nValue of UK = "<<it1->second;

    //count(m) prints 1 if element m exists and 0 if it doesn't exist. 
    //return type is size_t
    if(m.count("India")) 
        cout<<"\nIndia Exists in map";
    else
        cout<<"\nIndia doesn't exists in map";

    cout<<"\nSize of map "<<m.size();





    return 0;
}