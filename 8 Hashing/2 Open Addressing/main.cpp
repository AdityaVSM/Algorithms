#include<bits/stdc++.h>
using namespace std;
/**
 * Open addressing using Linear probing
 * while deleting replace empty slots by -99 (Assuming -99 not in data to be entered) 
 * i,e -99 means deleted and -98 means empty
 */
class MyHash{
    public:
        int size, capacity;
        int *table;
        MyHash(int capacity){
            size=0;
            this->capacity = capacity;
            table = new int[capacity];
            for(int i=0;i<capacity;i++)
                table[i]=-98;
        };
        int hash(int val){
            return val%capacity;
        }
        bool del(int val){  //returns true if successfully deleted else false
            int h = hash(val);
            int i = h;
            while(table[i]!=-98){
                if(table[i]==val){
                    table[i] = -99; //place -99 in deleted location
                    return true;
                }
                i = (i+1)%capacity;
                if(i==h)
                    return false;                    
            }
            return false;
        }
        bool insert(int key){   //returns true if successfully inserted else false
            if(size==capacity)
                return false;
            int i=hash(key);
            while(table[i]!=-98 && table[i]!=-99 && table[i]!=key)
                i=(i+1)%capacity;
            if(table[i]==key)
                return false;
            else{
                table[i]=key;
                size++;
                return true;
            }
        }
        bool search(int val){
            int h = hash(val);
            int i=h;
            while(table[i]!=-98){
                if(table[i]==val)
                    return true;
                i = (i+1)%capacity; //because this is circular array traversal
                if(i==h)    //returned to same location after completing cycle
                    return false;
            }
            return false;
        }
};

int main(){

    MyHash hash(7);
    cout<<hash.insert(12)<<endl;
    hash.del(12);
    cout<<hash.search(12);

    return 0;
}