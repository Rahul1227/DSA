const int MOD = 1e9+7;
class Solution {
private:
    long long getPower(int base, int power){
        if(power == 0){
            return 1;
        }

        long long half = getPower(base, power/2);
        long long ans = (half * half) % MOD;
        if(power%2 != 0){
            ans = (ans * base) % MOD;
        }

        return ans;
    }
    void dfs(int node, int &currLen, int &maxLen, vector<int> &visited, vector<vector<int>> &adj){
        if(visited[node]) return;
        visited[node] = 1;
        currLen++;
        maxLen = max(maxLen, currLen);
        
        for(auto v : adj[node]){
            dfs(v, currLen, maxLen, visited, adj);
        }


        visited[node] = 0;
        currLen--;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+2);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxLen =  0;
        int currLen = -1;
        vector<int> visited(n+2, 0);

        dfs(1, currLen, maxLen, visited, adj);

        return getPower(2, maxLen-1);
        
        
    }
};