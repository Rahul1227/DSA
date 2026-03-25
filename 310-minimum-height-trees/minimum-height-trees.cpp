class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        for(int i =0; i<n; i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }

        while(n > 2){
            int len = q.size();
            n -= len;
            for(int i =0; i<len; i++){
                auto u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    indegree[v]--;
                    if(indegree[v] == 1){
                        q.push(v);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
        
    }
};