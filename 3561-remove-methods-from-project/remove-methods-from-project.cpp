class Solution {
private:
    void bfs(int src, vector<int> &visited, bool &canReach, vector<vector<int>> &adj, int fill){
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(fill != 1 && visited[node] == 1){
                canReach = true;
                return;
            }
            visited[node] = fill;

            for(auto v : adj[node]){
                if(visited[v] != fill){
                    q.push(v);
                }
            }
            

        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto invo : invocations){
            int u = invo[0];
            int v = invo[1];
            adj[u].push_back(v);
        }

        vector<int> visited(n, 0);
        bool canReach = false;

        bfs(k, visited, canReach, adj, 1);
        vector<int> ans;
        for(int i =0; i<n; i++){
            ans.push_back(i);
        }
        for(int i =0; i<n; i++){
            if(visited[i]== 0){
                bfs(i, visited, canReach, adj, 2);
                if(canReach){
                    return ans;
                }

            }
        }

        ans.clear();
        for(int i=0; i<n; i++){
            if(visited[i] != 1){
                ans.push_back(i);
            }
        }

        return ans;
        
    }
};