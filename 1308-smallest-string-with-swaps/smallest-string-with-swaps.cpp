class DisjointSet{
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n){
        parent.resize(n);
        size.assign(n,1);

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

        if(parentU == parentV) return;

        if(size[parentU] >= size[parentV]){
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }else{
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
    }


    vector<int> getParent(){
        for(int i =0;  i< parent.size(); i++){
            parent[i] = findUltimateParent(i);
        }
        return parent;
    }

   
    
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DisjointSet ds(n);
        for(auto pair : pairs){
            int u = pair[0];
            int v = pair[1];
            ds.unionBySize(u,v);
        }

        vector<int> par = ds.getParent();
        unordered_map<int, vector<char>> mp;

        for(int i=0; i<n; i++){
            mp[par[i]].push_back(s[i]);
        }

        for(auto &[key, val]: mp){
            sort(val.begin(), val.end());
            cout<<key<<" -> ";
            for(auto v  : val){
                cout<<v<<" ";
            }
        }

        vector<int> currInd(n, 0);
        string ans ="";

        for(int i=0; i<n; i++){
            ans += mp[par[i]][currInd[par[i]]];
            currInd[par[i]]++;

            
        }
        return ans;


        
    }
};