class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(int i =0; i<n; i++){
            if(!graph[i].size()) continue;
            int v = i;
            for(auto u : graph[i]){
                adj[u].push_back(v);
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int i =0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans(n);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans[u] = 1;

            for(auto v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        vector<int> finalAns;
        for(int i =0; i<n; i++){
            if(ans[i] ==1){
                finalAns.emplace_back(i);
            }
        }
        return finalAns;

        
    }
};