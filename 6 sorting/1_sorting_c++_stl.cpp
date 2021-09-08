#include<bits/stdc++.h>
using namespace std;
/*
-> sort() uses hybrid of (quick sort, heap sort, insertion sort) whichever is faster based on the
array/vector size.
-> worst case time complexity is O(nlogn).
*/
struct Point{
    int x,y;
};

bool myComp(Point p1, Point p2){
    return p1.x > p2.x;     //Decreasing order of x
}
int main(){
    Point a[] = {{1,2},{3,4},{5,6}};
    int n = 3;
    sort(a,a+n,myComp);
    for(auto i : a){
        cout << "{"<<i.x <<","<<i.y <<"} ";
    }
    return 0;
}