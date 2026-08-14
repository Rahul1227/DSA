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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(isConnected[i][j] == 1){
                    ds.unionBySize(i,j);
                }
            }
        }

        vector<int> par  = ds.getParent();

        int count = 0;
        for(int i=0; i<n; i++){
            if(par[i] == i){
                count++;
            }
        }

        return count;
        
    }
};