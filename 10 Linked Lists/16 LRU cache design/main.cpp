#include<bits/stdc++.h>

//Use doubly ll and hash table

using namespace std;
class DllNode { 
    public:
        int key; 
        int value; 
        DllNode *pre; 
        DllNode *next; 
        
        DllNode(int k, int v){ 
            key = k; 
            value = v;
            this->pre=NULL;
            this->next=NULL;
        } 
}; 

class LRUCache{
    public:
        unordered_map<int, DllNode*> map;
        int capacity, count;
        DllNode* head, *tail;

        LRUCache(int capacity){
            this->capacity = capacity;
            head = new DllNode(0,0);
            tail = new DllNode(0,0);
            head->next = tail;
            tail->pre = head;
            head->pre = NULL;
            tail->next = NULL;
            count = 0;
        }

        void deleteNode(DllNode* node){
            node->pre->next = node->next;
            node->next->pre = node->pre;
            delete(node);
        }

        void addToHead(DllNode* node){
            node->next = this->head;
            this->head->pre = node;
            this->head = node;
        }

        int get(int key){
            if(this->map[key]!=NULL){
                DllNode* node = map[key];
                int res = node->value;
                deleteNode(node);
                addToHead(node);
                cout<<"Got the value "<<res<<" for the key "<<key<<endl;
                return res;
            }
            cout<<"Did not get any value for key "<<key<<endl;
            return -1;
        }

        void set(int key, int value){
            cout<<"Going to set the (key, value) : (" << key << ", " << value << ")"<<endl; 
            if (map[key] != NULL) { 
                DllNode *node = map[key]; 
                node->value = value; 
                deleteNode(node); 
                addToHead(node); 
            } 
            else { 
                DllNode *node = new DllNode(key, value); 
                map[key]= node; 
                if (count < capacity) { 
                    count++; 
                    addToHead(node); 
                } 
                else { 
                    map.erase(this->tail->pre->key); 
                    deleteNode(this->tail->pre); 
                    addToHead(node); 
                } 
            } 
        }
};

int main(){
    LRUCache cache(2); 
    // it will store a key (1) with value 10 in the cache. 
    cache.set(1, 10); 
    // it will store a key (2) with value 20 in the cache. 
    cache.set(2, 20); 
    cout<<"Value for the key: 1 is " << cache.get(1)<<endl; // returns 10 

    // removing key 2 and store a key (3) with value 30 in the cache. 
    cache.set(3, 30); 

    cout<<"Value for the key: 2 is " <<  cache.get(2)<<endl; // returns -1 (not found) 

    // removing key 1 and store a key (4) with value 40 in the cache. 
    cache.set(4, 40); 
    cout<<"Value for the key: 1 is " << cache.get(1)<<endl; // returns -1 (not found) 
    cout<<"Value for the key: 3 is " << cache.get(3)<<endl; // returns 30 
    cout<<"Value for the key: 4 is " << cache.get(4)<<endl; // return 40 
    
    return 0;
}