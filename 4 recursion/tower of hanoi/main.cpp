#include<bits/stdc++.h>
using namespace std;
int toh(int N, char from, char to, char aux){
    int count=0;
    if(N==1){
        cout<<"move disk 1 from rod "<<from<<" to rod "<<to<<endl;
        return count+1;
    }
    count+=toh(N-1,from,aux,to);
    cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
    count+=toh(N-1,aux,to,from);
    return count+1;
}

int main(){
    cout<<toh(3,'s','d','t')<<endl;
    return 0;
}