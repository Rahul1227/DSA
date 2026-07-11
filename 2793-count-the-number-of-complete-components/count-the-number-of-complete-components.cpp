class Solution {
private:
    bool isComplete(unordered_map<int,int> &nodes, vector<vector<int>> &adj){
        for(auto [node, count] : nodes){
            if(adj[node].size() < nodes.size() -1) return false;
            for(auto v: adj[node]){
                if(!nodes.count(v)) return false;
            }
        }
        return true;

    }
    int bfs(int ind, vector<vector<int>> &adj, vector<int> &visited){
        queue<int> q;
        visited[ind] = 1;
        q.push(ind);
        unordered_map<int, int> nodes;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            nodes[u]=1;
            for(auto v : adj[u]){
                if(!visited[v]){
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }

        if(isComplete(nodes, adj)){
            return 1;
        }
        return 0;

        


    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int componentCount = 0;
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                
                componentCount += bfs(i, adj, visited);;
            }
        }

        return componentCount;
        
    }
};