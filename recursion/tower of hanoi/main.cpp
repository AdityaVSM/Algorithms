#include<bits/stdc++.h>
using namespace std;
void toh(int n, char s, char d, char t){
    if(n==1){
        cout<<"move disc "<<1<<" from "<<s<<" to "<<t<<endl;
        return;
    }
    toh(n-1,s,t,d);
    cout<<"Move disc "<<n<<" from "<<s<<" to "<<t<<endl;
    toh(n-1,d,s,t);
}
int main(){
    toh(3,'s','d','t');
    return 0;
}