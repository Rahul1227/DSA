using pii = pair<int,long long>;
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int V = roads.size() + 1;
        vector<vector<int>> adj(V);
        vector<pii> degree(V,{0,1});

        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u].first++;
            degree[v].first++;
        }

        queue<int> q;
        long long totalCost =0;

        for(int i=0; i<V; i++){
            if(degree[i].first == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == 0) continue;
            if(degree[node].first == 0) continue;
            degree[node].first--;
            totalCost += 1LL*ceil(1.00 *degree[node].second/seats);
            

            for(auto v : adj[node]){
                if(degree[v].first > 0){
                    degree[v].first--;
                    degree[v].second += 1LL *degree[node].second;

                    if(degree[v].first == 1){
                        q.push(v);
                    }
                }
            }
        }
        return totalCost;
        
    }
};