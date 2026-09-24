class Solution {
private:
    bool bfs(int src, vector<vector<int>> &graph, vector<int> &color){
        queue<int> q;
        q.push(src);
        color[src] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            int currColor = color[u];

            for(auto v : graph[u]){
                if(color[v] == -1){
                    color[v] = 1 - currColor;
                    q.push(v);
                }else{
                    if(color[v] == currColor) return false;
                }
            }
        }

        return true;

    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!bfs(i, graph, color)) return false;
            }
        }

        return true;
        
    }
};