using  P = pair<int,int>;
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<P>> adj(n);

        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }

        vector<int> distance(n, INT_MAX);

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,0});
        distance[0] = 0;

        while(!pq.empty()){
            auto [u, dist] = pq.top();
            pq.pop();

            for(auto &[v, storedDistance] : adj[u]){
                int newDistance = dist + storedDistance;

                if(newDistance < distance[v]){
                    distance[v] = newDistance;
                    pq.push({v, newDistance});
                }
            }
        }

       return (distance[n-1] != INT_MAX ? distance[n-1] : -1);

        
    }
};