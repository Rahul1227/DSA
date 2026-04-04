class DisjointSet{
    private:
        vector<int> parent;
        vector<int> size;
    
    public:
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n,1);

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

            if(size[parentU] >= size[parentV]){
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

            return count;
        }

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n);

        for(int i =0; i<n; i++){
            int row = stones[i][0];
            int col = stones[i][1];

            for(int j=i+1; j<n; j++){
                int currRow = stones[j][0];
                int currCol = stones[j][1];

                if(currRow == row || currCol == col){
                    ds.unionBySize(i,j);
                }
            }
        }

        int count = ds.getResult();
        return n - count;
        
    }
};