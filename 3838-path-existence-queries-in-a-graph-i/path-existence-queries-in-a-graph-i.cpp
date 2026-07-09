class Solution {
private:
    void bfs(int i, vector<int> &component, int componentId, vector<vector<int>> &adj){
        if(component[i] != -1) return;
        component[i] = componentId;
        for(auto v : adj[i]){
            bfs(v, component, componentId, adj);
        }
    }
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i =0; i+1< n; i++){
            if(nums[i+1] - nums[i] <= maxDiff){
                int u = i;
                int v = i+1;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        vector<int> component(n, -1);
        int componentId = -1;
        for(int i =0; i<n; i++){
            if(component[i] == -1){
                componentId++;
                bfs(i, component, componentId, adj);
            }
        }

        vector<bool> ans;
        for(auto query: queries){
            int u = query[0];
            int v = query[1];
            ans.push_back(component[u] == component[v]);
        }
        return ans;
        
    }
};