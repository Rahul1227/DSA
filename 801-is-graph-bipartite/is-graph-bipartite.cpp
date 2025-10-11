class Solution {
private:
    bool check(int i, int color, vector<int> &colors, vector<vector<int>> &graph){
        queue<pair<int,int>> q;
        q.push({i,color});
        while(!q.empty()){
            auto [node, col] = q.front();
            q.pop();

            for(auto adjNode : graph[node]){
                if(colors[adjNode] == -1){
                    colors[adjNode] = 1-col;
                    q.push({adjNode, colors[adjNode]});
                }else{
                    if(colors[adjNode] == col){
                        return false;
                    }
                }
            }
        }

        return true;

    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for(int i =0; i<n; i++){
            if(colors[i] == -1){
                if(!check(i,0,colors, graph)){
                    return false;
                }
            }
        }
        return true;
        

    }
};