class LRUCache {
    int n;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) { n = capacity; }

    int get(int key) {
        if (mp.count(key)) {
            auto it = mp[key];
            auto [key, val] = *it;
            l.erase(it);
            l.push_back({key, val});
            mp[key] = prev(l.end());
            return val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            auto it = mp[key];
            l.erase(it);
            l.push_back({key, value});
            mp[key] = prev(l.end());

        } else {
            if (l.size() == n) {
                auto [delKey, val] = l.front();
                // cout<<"We are deleting "<<delKey<<endl;
                mp.erase(delKey);
                l.pop_front();
            }
            l.push_back({key, value});
            mp[key] = prev(l.end());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */