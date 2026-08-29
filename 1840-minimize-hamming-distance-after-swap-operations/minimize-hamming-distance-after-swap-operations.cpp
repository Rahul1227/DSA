class DSU{
private:
    vector<int> size;
    vector<int> parent;
public:

    DSU(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;

        }
    }

    int findUltimateParent(int u){
        if(parent[u] == u){
            return u;
        }

        return parent[u] = findUltimateParent(parent[u]);
    }

    void unionBySize(int u, int v){
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        if(parentU == parentV){
            return;
        }

        if(size[parentU] >= size[parentV]){
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }else{
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
    }

    vector<int> getParent(){
        for(int i=0; i<parent.size(); i++){
            parent[i] = findUltimateParent(i);
        }

        return parent;
    }

};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU ds(n);
        for(int i=0; i<allowedSwaps.size(); i++){
            int u = allowedSwaps[i][0];
            int v = allowedSwaps[i][1];
            ds.unionBySize(u,v);
        }

        unordered_map<int, unordered_multiset<int>> mp;
        vector<int> parent = ds.getParent();
        for(int i=0; i<parent.size(); i++){
            int currParent = parent[i];
            
            mp[currParent].insert(source[i]);
            source[i] = currParent;
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            int currParent = source[i];
            auto &st = mp[currParent];
            auto it = st.find(target[i]);
            if(it == st.end()){
                ans++;
            }else{
                st.erase(it);
            }
        }

        return ans;

        
    }
};