#include<bits/stdc++.h>
using namespace std;
int main(){
    char s1[] = "gfg"; //[[g][f][g][\0]] -> memory allocation
    char s2[5] = "gfg"; //[[g][f][g][\0][\0]] -> memory allocation
    cout<<"sizeOf(s1) = "<<sizeof(s1)<<" sizeOf(s2) = "<<sizeof(s2)<<endl;

    /*char s3[] = {'g','f','g'};
    cout<<s3<<endl; //gfg and then random characters until it finds \0 in memory*/
    char s3[] = {'g','f','g','\0'};
    cout<<s3<<endl; //gfg as it finds \0 in memory

    return 0;
}