class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int N = n+1;
        vector<vector<pair<int,int>>>adj(N);
        for(int i=0; i<times.size(); i++){
            int u =  times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }

        vector<int> dist(N, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k}); //distance, node
        dist[k] = 0;

        while(!pq.empty()){
            auto [distance, u] = pq.top();
            pq.pop();

            if(distance > dist[u]) continue;

            for(auto [v,w] : adj[u]){
                int newDist = distance + w;
                if(newDist < dist[v]){
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }

    

        int maxTime = *max_element(dist.begin()+1, dist.end());
        return maxTime != INT_MAX ? maxTime : -1;
        
    }
};