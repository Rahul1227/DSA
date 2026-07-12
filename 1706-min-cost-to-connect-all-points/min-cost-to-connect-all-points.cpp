using pii = pair<int,int>;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // v, w
        vector<vector<pii>> adj(n);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> visited(n,0);
        int cost = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                // if(i==j) continue;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int distance = abs(x2-x1) + abs(y2 - y1);
                adj[i].push_back({j, distance});
                adj[j].push_back({i, distance});

            }
        }
        // cost, node
        pq.push({0,0});
        while(!pq.empty()){
            // auto topEle = pq.top();
            // int weight = topEle.first;
            // int node = topEle.second;
            auto [weight, node] = pq.top();
            pq.pop();
            if(visited[node]) continue;

            visited[node] = 1;
            cost += weight;

            for(auto [v, w] : adj[node]){
                if(!visited[v]){
                    pq.push({w,v});
                }
            }

        }

        return cost;
        
    }
};