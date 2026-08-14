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

    bool isConnected(int u, int v){
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        return parentU == parentV;

    }

   
    
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        DisjointSet ds(n);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            if(ds.isConnected(u,v)){
                return {u,v};
            }
            ds.unionBySize(u,v);
        }

        return {};
        
    }
};