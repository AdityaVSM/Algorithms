#include<bits/stdc++.h>
using namespace std;
/*
count the number of distinct elements in the array

ex:
    arr = {5,3,2,4,5,3}
    res = 4
*/
int naive(vector<int> a){   //O(n*n):time and O(1) : space
    int n = a.size();
    int res = 0;
    for(int i=0; i<n; i++){
        bool exists = false;
        for(int j=0;j<i;j++){
            if(a[j] == a[i])
                exists = true;
        }
        if(!exists)
            res++;
    }
    return res;
}

//Use Set(unordered_set in c++) which does not store repeated elements
int efficient(vector<int> a){   //O(n):time and O(n):space
    int n = a.size();
    // unordered_set<int> set(a,a+n);   (works if a is an array)
    unordered_set<int> set;
    for(int i=0; i<n; i++){
        set.insert(a[i]);
    }
    return set.size();
}

int main(){
    vector<int> a {5,4,5};
    cout << naive(a) << endl;
    cout << efficient(a) << endl;

    return 0;
}