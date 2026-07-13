class TreeAncestor {
    int col;
    vector<vector<int>> ancestor;
public:
    TreeAncestor(int n, vector<int>& parent) {
        col = log2(n) + 1;
        ancestor.resize(n, vector<int>(col,-1));

        // filling the first col
        for(int i=0; i<n; i++){
            ancestor[i][0] = parent[i];
        }

        for(int j=1; j<col; j++){
            for(int i=0; i<n; i++){
                if(ancestor[i][j-1] != -1){
                    ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int ans = node;
        for(int i =0; i<col; i++){
            if(k & (1 << i)){
                ans = ancestor[ans][i];
                if(ans == -1) return -1;
            }
        }
        return ans;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */