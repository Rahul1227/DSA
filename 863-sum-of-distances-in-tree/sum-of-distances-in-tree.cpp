class Solution {
private:
    void dfs1(int src, int parent, vector<int> &size, vector<int> &dist, vector<vector<int>> &adj){
        for(auto v : adj[src]){
            if(v == parent) continue;
            dfs1(v,src,size,dist,adj);
            size[src] += size[v];
            dist[src] += dist[v] + size[v];
        }

    }

    void dfs2(int src, int parent, vector<int>&ans, vector<int> &size, vector<vector<int>> &adj, int n){
        for(auto v : adj[src]){
            if( v == parent) continue;
            // if(parent == -1) continue;
            ans[v] = ans[src] + n - 2*size[v];
            dfs2(v,src,ans,size,adj,n);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> size(n, 1);
        vector<int> dist(n, 0);
        vector<int> ans (n,0);

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        

        dfs1(0,-1,size,dist,adj);

        ans[0] = dist[0];
        dfs2(0,-1,ans, size,adj,n);
        return ans;

        
    }
};