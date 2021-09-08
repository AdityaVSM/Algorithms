#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<(32&40) << endl;
    cout<<(5|4) << endl;
    cout<<(5^4) << endl;
    cout<<(4<<0)<<" "<<(4<<1)<<" "<<(4<<2)<<endl;
    cout<<(4>>1)<<" "<<(4>>3)<<endl;
    unsigned int x1=pow(2,32)-1,x2=pow(2,32)-2,x3=pow(2,32)-3 ;
    int y = 8;
    cout<<(~x1)<<" "<<(~x2)<<" "<<(~x3)<<" "<<(~y)<<" "<<(~5)<<endl;   
    return 0;
}