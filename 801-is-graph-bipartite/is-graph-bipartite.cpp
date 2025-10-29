class Solution {
private:
    bool check(vector<vector<int>> &graph, int src, vector<int> &color){
        queue<pair<int,int>> q;
        q.push({src,0});
        color[src] = 0;
        while(!q.empty()){
            auto [node, col]= q.front();
            q.pop();

            for(auto adjNode :graph[node]){
                if(color[adjNode] == -1){
                    int newColor =  1 - col;
                    color[adjNode] = newColor;
                    q.push({adjNode, newColor});
                }else{
                    if(col == color[adjNode]){
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
        vector<int> color(n,-1);
        for(int i =0; i< n; i++){
            if(color[i] == -1){
                if(!check(graph,i,color)){
                    return false;
                }
            }
        }
        return true;
       


        
    }
};