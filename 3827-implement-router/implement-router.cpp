struct Packet {
    int s, d, t;
};

struct TripleHash {
    size_t operator()(const tuple<int,int,int>& x) const {
        auto [a, b, c] = x;
        return ((size_t)a * 1315423911u) ^ ((size_t)b << 21) ^ ((size_t)c);
    }
};

class Router {
    queue<Packet> q;
    unordered_set<tuple<int,int,int>, TripleHash> st;
    unordered_map<int, vector<int>> mp;  // destination -> sorted timestamps
    int maxSize;

public:
    Router(int memoryLimit) {
        maxSize = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        auto key = make_tuple(source, destination, timestamp);

        if (st.find(key) != st.end()) return false;

        if (q.size() == maxSize) {
            Packet p = q.front(); q.pop();
            auto oldKey = make_tuple(p.s, p.d, p.t);
            st.erase(oldKey);

            auto &vec = mp[p.d];
            auto it = lower_bound(vec.begin(), vec.end(), p.t);
            if (it != vec.end() && *it == p.t) vec.erase(it);
        }

        st.insert(key);
        mp[destination].push_back(timestamp); // always increasing
        q.push({source, destination, timestamp});
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        Packet p = q.front(); q.pop();
        auto key = make_tuple(p.s, p.d, p.t);
        st.erase(key);

        auto &vec = mp[p.d];
        auto it = lower_bound(vec.begin(), vec.end(), p.t);
        if (it != vec.end() && *it == p.t) vec.erase(it);

        return {p.s, p.d, p.t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &vec = mp[destination];
        auto it1 = lower_bound(vec.begin(), vec.end(), startTime);
        auto it2 = upper_bound(vec.begin(), vec.end(), endTime);
        return distance(it1, it2);  // O(log n)
    }
};
