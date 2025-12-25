class LRUCache {
    list <int> dll;
    map<int, pair<list<int> :: iterator, int>> mp;
    int n;
public:
    LRUCache(int capacity) {
        n = capacity;
        
    }

    void makeLatest (int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        // if the key is present
        // we should make it the latest key
        makeLatest(key);


        return mp[key].second;
    }
    
    void put(int key, int value) {
        // if the key is present
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeLatest(key);
        }else{
            // if not present
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;


            // check if there are more than the allocated elements
            if(n < 0){
                int toDelete = dll.back();
                dll.pop_back();
                mp.erase(toDelete);
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