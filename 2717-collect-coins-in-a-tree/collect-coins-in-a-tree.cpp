class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(!coins[i] && degree[i] == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            // if(degree[u] == 0) continue;
            degree[u]--;
           
            for(auto v: adj[u]){
                if(degree[v] == 0) continue;
                degree[v]--;
                if(!coins[v] && degree[v] == 1){
                    q.push(v);
                }
            }
        }

        for(int i=0; i<2; i++){
            queue<int> q2;
            for(int i=0; i<n; i++){
                if(degree[i] == 1){
                    q2.push(i);
                }
            }

            while(!q2.empty()){
                int u = q2.front();
                q2.pop();
                // if(degree[u] == 0) continue;
                degree[u]--;
                for(auto v : adj[u]){
                    if(degree[v] == 0) continue;
                    degree[v]--;
                }
            }
        }
        // for(auto num: degree){
        //     cout<<num<<" ";
        // }
        int count = 0;
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            if(degree[u]>0 && degree[v]>0){
                count++;
            }
        }

        return count * 2;
        
    }
};