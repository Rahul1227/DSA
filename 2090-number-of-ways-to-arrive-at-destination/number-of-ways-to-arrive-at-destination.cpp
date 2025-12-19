class Solution {
    const int MOD = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // creating the adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for(int i =0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w}); // birectional paths
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> count(n,0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0}); // distance , node
        dist[0] = 0;
        count[0] = 1;

        while(!pq.empty()){
            auto [distance, u] = pq.top();
            pq.pop();

            if(distance > dist[u]) continue;

            for(auto [v,w] : adj[u]){
                long long newDist = distance + w;
                if(newDist < dist[v]){
                    dist[v] = newDist;
                    pq.push({newDist, v});
                    count[v] = count[u] % MOD;
                }else if(newDist == dist[v]){
                    count[v] = (count[v] + count[u]) % MOD;
                }
            }
        }

        return count[n-1];



        
    }
};