class Solution {
private:
    void dfs1(int src, int parent, vector<int> &dp, vector<vector<pair<int,int>>> &adj){
        for(auto [v,w] : adj[src]){
            if(v == parent) continue;
            dfs1(v, src, dp, adj);
            dp[src] += dp[v] + w;
        }
    }

    void dfs2(int src, int parent, vector<vector<pair<int,int>>> &adj, vector<int> &ans){
        for(auto [v,w] : adj[src]){
            if(v == parent) continue;
            ans[v] = ans[src] + 1 - 2*w;
            dfs2(v, src, adj, ans);
        }
    }
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }

        vector<int> dp(n, 0);
        vector<int> ans(n, 0);
        dfs1(0, -1, dp, adj);
        ans[0] = dp[0];              // seed the root's true answer
        dfs2(0, -1, adj, ans);

        return ans;
    }
};