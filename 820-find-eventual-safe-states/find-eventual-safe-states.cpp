class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> outDegree(V, 0);
        vector<vector<int>> adj(V);
        for(int i=0; i<V; i++){
            outDegree[i] = graph[i].size();
            for(int j =0; j< graph[i].size(); j++){
                adj[graph[i][j]].push_back(i);

            }
        }

        vector<int> ans;
        queue<int> q;

        for(int i =0; i<V; i++){
            if(outDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto v : adj[node]){
                if(outDegree[v] > 0){
                    outDegree[v]--;
                    if(outDegree[v] == 0){
                        q.push(v);
                    }
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
        
    }
};