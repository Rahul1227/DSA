class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int PossibleIteration = k+1;
        vector<int> dist(n, INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i< flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }

        queue<pair<int,int>> q;
        
        q.push({src,0});
        dist[src] = 0;

        while(!q.empty() && PossibleIteration){
            int len = q.size();
            for(int times =0; times<len; times++){
                auto [u, distance] = q.front();
                q.pop();

                for(auto [v, w] : adj[u]){
                    int newDist = distance + w;
                    if(newDist < dist[v]){
                        dist[v] = newDist;
                        q.push({v, newDist});
                    }
                }
            }
            PossibleIteration--;
            
        }

        return dist[dst] != INT_MAX ? dist[dst] : -1;
        
    }
};