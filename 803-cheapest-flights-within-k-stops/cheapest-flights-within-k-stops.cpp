using pii = pair<int,int>;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pii> q;
        q.push({src, 0});
        k++;
        vector<vector<pii>> adj(n);

        for(auto edge : flights){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
        }

        while(!q.empty() && k>0){
            int len = q.size();
            for(int i=0; i<len; i++){
                auto [u, weight] = q.front();
                q.pop();

                for(auto [v,w] :  adj[u]){
                    int newDist = weight + w;
                    if(newDist < dist[v]){
                        dist[v] = newDist;
                        q.push({v, newDist});
                    }
                }

            }
            k--;
        }

        if(dist[dst] >= INT_MAX) return -1;
        return dist[dst];
        
    }
};