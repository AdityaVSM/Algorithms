#include<bits/stdc++.h>
using namespace std;
/*
* unordered sets are implemented using hashing
* elements are arranged internally in any random order
* No repetitive elements are stored

set.begin() ->  O(1)
set.cbegin() -> O(1)
set.end() ->    O(1)
set.cend() ->   O(1)

set.erase(it) ->    O(1)
set.erase(ele) ->   O(1)
set.count() ->      O(1)
set.find() ->       O(1)
set.insert() ->     O(1)

*/
int main(){
    unordered_set<int> set;
    set.insert(10);
    set.insert(15);
    set.insert(12);
    set.insert(13);
    //Printing elements
    for(auto it=set.begin(); it!=set.end(); it++)
        cout<<(*it)<<" ";
    
    cout<<"\nSize is "<<set.size();

    //set.find(m) returns iterator(address) of element m
    if(set.find(12)==set.end()) 
        cout<<"\nMatching location";
    else
        cout<<"\nLocation not same";

    //count(m) prints 1 if element m exists and 0 if it doesn't exist
    if(set.count(12)) 
        cout<<"\n12 Exists in set";
    else
        cout<<"\n12 doesn't exists in set";

    //set.erase(m,n) deletes all elements from m to n where m and n are iterators
    //set.erase(m) deletes m where m can be iterator or element to a element
    set.erase(15);
    cout<<"\nSize after erasing "<<set.size();

    //set.clear() clears all elements from set
    set.clear();
    cout<<"\nSize after clearing is "<<set.size();

    
    return 0;
}