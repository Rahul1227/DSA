class DisjointSet{
private:
    vector<int> size;
    vector<int> parent;

public:
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i =0; i<n; i++){
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

        if(size[parentU] > size[parentV]){
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }else{
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
    }

    int getResult(){
        int count = 0;
        for(int i =0; i< parent.size(); i++){
            if(parent[i] == i){
                count++;
            }
        }

        return count-1;
    }

    
};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        if(len < n-1) return -1;

        DisjointSet ds(n);

        for(int i =0; i<len; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            ds.unionBySize(u,v);
        }

        return ds.getResult();

        
    }
};