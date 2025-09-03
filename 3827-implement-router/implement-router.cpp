class Router {
    queue<vector<int>> q;
    unordered_set<string> st;
    unordered_map<int, vector<int>> mp;
    int maxSize;

public:
    Router(int memoryLimit) { maxSize = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        string str = to_string(source) + "S" + to_string(destination) + "D" +
                     to_string(timestamp) + "T";

        if (st.find(str) != st.end())
            return false;

        if (q.size() == maxSize) {
            vector<int> popedElement = q.front();
            q.pop();
            int s = popedElement[0];
            int d = popedElement[1];
            int t = popedElement[2];
            string str1 =
                to_string(s) + "S" + to_string(d) + "D" + to_string(t) + "T";
            st.erase(str1);
            auto& vec = mp[d];
            auto it = lower_bound(vec.begin(), vec.end(), t);
            if (it != vec.end()) {
                vec.erase(it);
            }
        }
        st.insert(str);
        mp[destination].push_back(timestamp);
        q.push({source, destination, timestamp});
        return true;
    }

    vector<int> forwardPacket() {
        if (q.size() == 0)
            return {};
        vector<int> popedElement = q.front();
        q.pop();
        int s = popedElement[0];
        int d = popedElement[1];
        int t = popedElement[2];
        string str1 =
            to_string(s) + "S" + to_string(d) + "D" + to_string(t) + "T";
        st.erase(str1);
        auto& vec = mp[d];
        auto it = lower_bound(vec.begin(), vec.end(), t);
        if (it != vec.end()) {
            vec.erase(it);
        }

        return {s, d, t};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& vec = mp[destination];
        // find first element >= startTime
        auto it1 = lower_bound(vec.begin(), vec.end(), startTime);
        // find first element > endTime
        auto it2 = upper_bound(vec.begin(), vec.end(), endTime);
        return distance(it1, it2); // O(log n)
    }
};

    /**
     * Your Router object will be instantiated and called as such:
     * Router* obj = new Router(memoryLimit);
     * bool param_1 = obj->addPacket(source,destination,timestamp);
     * vector<int> param_2 = obj->forwardPacket();
     * int param_3 = obj->getCount(destination,startTime,endTime);
     */