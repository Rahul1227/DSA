class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> adj(n+1);
        vector<int> degree(n+1, 0);

        for(auto &road: roads){
            int u = road[0];
            int v = road[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        vector<long long> people(n+1, 1);
        for(int i=1; i<=n; i++){
            if(degree[i] == 1){
                q.push(i);
                degree[i]--;
            }
        }
        long long totalCost = 0LL;

        while(!q.empty()){
            auto u = q.front();
            q.pop();
            if(u == 0) continue;

            totalCost += ceil(1.00 * people[u] / seats);

            for(auto v: adj[u]){
                if(degree[v] == 0 || v == 0) continue;
                people[v] += people[u];
                degree[v]--;
                if(degree[v] == 1){
                    q.push(v);
                }
                
            }
        }

        return totalCost;
        
    }
};