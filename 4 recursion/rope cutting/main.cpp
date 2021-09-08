#include<bits/stdc++.h>
using namespace std;

int numberOfPieces(int n,int a, int b, int c){
    if(n == 0) return 0;
    if(n < 0) return -1;
    
    //int res = max((numberOfPieces((n-a),a,b,c), numberOfPieces((n-b),a,b,c), numberOfPieces((n-c),a,b,c))); Doesn't work

    int res1 = max(numberOfPieces((n-a),a,b,c), numberOfPieces((n-b),a,b,c));
    int res = max(res1, numberOfPieces((n-c),a,b,c));
    
    if(res == -1) return -1;
    return res+1;
}
int main(){
    cout<<numberOfPieces(5,2,5,1)<<endl;
    return 0;   
}