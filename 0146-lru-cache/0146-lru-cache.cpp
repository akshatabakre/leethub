class LRUCache {
public:

    list<int> dll;
    map<int,pair<int,list<int>::iterator>> mp;//key,{val,it}
    int c;


    LRUCache(int capacity) {
        c = capacity;
    }

    void touch(int key){
        auto keynode = mp[key].second;
        dll.erase(keynode);
        dll.push_front(key);
        keynode = dll.begin();
        mp[key].second = keynode;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){//key not found
            return -1;
        }
        int val = mp[key].first;
        touch(key);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].first = value;
            touch(key);
        }else{
            if(dll.size()==c){
                int oldkey = dll.back();
                dll.pop_back();
                mp.erase(oldkey);

                dll.push_front(key);
                mp[key] = {value,dll.begin()};
            }else{
                dll.push_front(key);
                mp[key] = {value,dll.begin()};
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */