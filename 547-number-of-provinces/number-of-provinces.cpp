class Solution {
private:
    void bfs(int src, vector<int> &visited, vector<vector<int>> &adj){
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adjNode : adj[node]){
                if(!visited[adjNode]){
                    visited[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(i==j) continue;
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        // for(int i =0; i<n; i++){
        //     cout<<i<<" ";
        //     for(int j =0; j<adj[i].size(); j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        int result =0;
        vector<int> visited(n,0);

        for(int i =0; i<n; i++){
            if(!visited[i]){
                result++;
                bfs(i,visited,adj);
            }
        }

        return result;
    }
};