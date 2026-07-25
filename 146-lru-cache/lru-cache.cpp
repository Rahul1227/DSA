class LRUCache {
public:
    list<pair<int,int>> l;
    // key -> iterator
    map<int, list<pair<int,int>> :: iterator> mp;
    int n;
    int currCapacity = 0;
    LRUCache(int capacity) {
        n = capacity;
        
    }

    // void makeRecent(int key)
    
    int get(int key) {
        if(mp.count(key)){
            auto it = mp[key];
            int val = it->second;
            l.erase(it);
            l.push_front({key, val});
            mp[key] = l.begin();
            return val;
        }else{
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            l.erase(mp[key]);
            l.push_front({key, value});
            mp[key] = l.begin();
            // currCapacity++;

        }else{
            if(currCapacity == n){
                int toDeleteKey = l.back().first;
                mp.erase(toDeleteKey);
                l.pop_back();
                currCapacity--;
            }
            l.push_front({key, value});
            mp[key] = l.begin();
            currCapacity++;

        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */