class LFUCache {
public:

    int capacity, size, lfu = 0;
    unordered_map<int,list<int>> freqlist;//freq->list of nodes
    unordered_map<int,pair<int,int>> cache;//key->{val,freq}
    unordered_map<int,list<int>::iterator> iter;

    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }

    void touch(int key){
        int oldf = cache[key].second;//map
        auto it = iter[key];
        freqlist[oldf].erase(it);//list delete
        freqlist[oldf+1].push_back(key);//list add
        cache[key].second++;//map update
        iter[key] = --freqlist[oldf+1].end();
        if(freqlist[lfu].empty()){
            lfu++;
        }
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }
        int val = cache[key].first;
        touch(key);
        return val;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            cache[key].first = value;
            touch(key);
        }else{
            if(size==capacity){
                //eviction
                int k = freqlist[lfu].front();
                freqlist[lfu].pop_front();
                cache.erase(k);
                iter.erase(k);
                size--;

                //add
                freqlist[1].push_back(key);
                cache[key] = {value,1};
                lfu = 1;
                size++;
                iter[key] = --freqlist[1].end();
            }else{
                freqlist[1].push_back(key);
                cache[key] = {value,1};
                lfu = 1;
                size++;
                iter[key] = --freqlist[1].end();
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */