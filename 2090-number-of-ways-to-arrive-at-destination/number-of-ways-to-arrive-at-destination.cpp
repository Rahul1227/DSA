using pill = pair<int,long long>;
using pii = pair<int,int>;
using plli = pair<long long, int>;
const int MOD = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pii>> adj(n);
        for(auto road: roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<pair<long long, long long>> distance(n, {LLONG_MAX,0LL});
        priority_queue<plli, vector<plli>, greater<>> pq;
        pq.push({0,0});
        distance[0] = {0, 1};

        while(!pq.empty()){
            auto [currDist, u] = pq.top();
            pq.pop();
            if(currDist > distance[u].first) continue;

            for(auto [v, w] : adj[u]){
                long long newDist = 1LL * currDist + w;
                if(newDist < distance[v].first){
                    pq.push({newDist, v});
                    distance[v] = {newDist, distance[u].second};
                }else if(newDist == distance[v].first){
                    distance[v].second = (distance[v].second +  distance[u].second) % MOD;
                }
            }

            
        }

        return distance[n-1].second;
        
    }
};