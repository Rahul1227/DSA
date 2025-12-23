class Solution {
private:
    int findUltimateParent(int u, vector<int> &par){
        if(u == par[u]){
            return u;
        }


        return par[u] = findUltimateParent(par[u], par);
    }

    void unionBySize(int u, int v, vector<int> &par, vector<int> &size){
        int parentU = findUltimateParent(u, par);
        int parentV = findUltimateParent(v, par);

        if(parentU ==  parentV) return;

        if(size[parentU] <= size[parentV]){
            par[parentU] = parentV;
            size[parentV] += size[parentU];
        }else{
            par[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }

    bool isConnected(int u, int v, vector<int> &par){
        int parentU = findUltimateParent(u, par);
        int parentV = findUltimateParent(v, par);

        return parentU == parentV;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        int len = connections.size();

        if(len < n-1) return -1;

        vector<int> par(n);
        vector<int> size(n,1);
        for(int i=0; i<n; i++){
            par[i] = i;
        }

        for(int i=0; i<len; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            unionBySize(u,v,par,size);

        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(i == par[i]){
                count++;
            }
        }

        return count-1;

        
    }
};