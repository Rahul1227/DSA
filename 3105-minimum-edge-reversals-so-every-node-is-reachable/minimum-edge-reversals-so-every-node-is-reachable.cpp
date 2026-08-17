class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> ans;

    void dfs1(int node, int parent) {
        for (auto& [nbr, cost] : adj[node]) {
            if (nbr == parent) continue;
            ans[0] += cost;
            dfs1(nbr, node);
        }
    }

    void dfs2(int node, int parent) {
        for (auto& [nbr, cost] : adj[node]) {
            if (nbr == parent) continue;
            ans[nbr] = ans[node] + (cost == 0 ? 1 : -1);
            dfs2(nbr, node);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        ans.assign(n, 0);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 0});  // u->v is the original direction, free
            adj[v].push_back({u, 1});  // v->u goes against original, costs 1
        }

        dfs1(0, -1);   // compute answer for node 0 only
        dfs2(0, -1);   // spread that answer to every other node

        return ans;
    }
};