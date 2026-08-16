class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
     

        for(auto connection : connections){
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
           

        int ans = 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> visited(n, 0);
        visited[0] = 1;

        while(!q.empty()){
            auto [node, w] = q.front();
            q.pop();
            ans += w;
            

            for(auto [v, weight] : adj[node]){
                if(!visited[v]){
                    q.push({v,weight});
                    visited[v] = 1;
                }
            }

        }

        return ans;
        
    }
};