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

        if(size[parentU] > size[parentV]){
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }else{
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
    }


    bool isConnected(int u, int v){
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        return parentU == parentV;

    }

   
    
};


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = 26;
        
        DisjointSet ds(n);
        // DisjointSet unequal(n);

        for(auto eq : equations){
            int u = eq[0] -'a';
            int v = eq[3] -'a';
            bool isEqual = (eq[1] == '=');

            if(isEqual){
                ds.unionBySize(u,v);
                
            }
        }

        for(auto eq : equations){
            int u = eq[0] -'a';
            int v = eq[3] -'a';
            bool isEqual = (eq[1] == '=');

            if(!isEqual){
                if(ds.isConnected(u,v)){
                    return false;
                }
                
            }
        }

        return true;

        
    }
};