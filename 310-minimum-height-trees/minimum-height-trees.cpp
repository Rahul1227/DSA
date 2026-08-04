class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return {0};
        }
        vector<vector<int>> adj(n);
        vector<int> ans;
        vector<int> degree(n, 0);

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for(int i =0; i<n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            ans.clear();
            int len = q.size();
            for(int i =0; i<len; i++){
                int node = q.front();
                q.pop();
                // if(degree[node] == 0) continue;
                degree[node]--;
                ans.push_back(node);

                for(auto v: adj[node]){
                    if(degree[v] > 0){
                        degree[v]--;
                        if(degree[v] == 1){
                            q.push(v);
                        }
                    }
                }
            }
        }
        return ans;

        
    }
};