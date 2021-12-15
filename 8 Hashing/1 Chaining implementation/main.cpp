#include<bits/stdc++.h>
using namespace std;

class MyHash{
    private:
        int bucket_size;
        list<int> *table;   
    public:
        MyHash(int bucket_size){
            this->bucket_size = bucket_size;
            table = new list<int>[bucket_size];
        };
        void del(int val){
            int key = val%bucket_size;
            table[key].remove(val);
        }
        void insert(int val){
            int key = val%bucket_size;
            table[key].push_back(val);
        }
        bool search(int val){
            int key = val%bucket_size;
            for(auto i : table[key]){
                if(i==val)
                    return true;
            }
            return false;
        }
};
int main(){
    MyHash hash(7);

    hash.insert(70);
    hash.insert(51);

    cout<<hash.search(70)<<endl;
    hash.del(51);
    cout<<hash.search(51)<<endl;

    return 0;
}