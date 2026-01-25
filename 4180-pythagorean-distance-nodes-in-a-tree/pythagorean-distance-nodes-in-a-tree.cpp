class Solution {
private:
    void solve(int ind, vector<int> &given, vector<vector<int>> &preCompute, vector<vector<int>> &adj, int n){
        queue<pair<int,int>> q;
        vector<int> visited(n,0);
        q.push({given[ind], 0});
        visited[given[ind]] = 1;

        while(!q.empty()){
            auto [u, distance] = q.front();
            q.pop();
            preCompute[ind][u] = distance;
            for(auto v : adj[u]){
                if(!visited[v]){
                    q.push({v, distance +1});
                    visited[v] = 1;
                }
            }
        }
    }

    bool checkPythagorus(vector<int> &distance){
        sort(distance.begin(), distance.end());
        long long a = 1LL * distance[0] * distance[0];
        long long b = 1LL * distance[1] * distance[1];
        long long c = 1LL * distance[2] * distance[2];

        return a + b == c;
    }
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);

        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u); // directed graph
        }

        vector<int> given = {x,y,z};

        vector<vector<int>> preCompute(3, vector<int>(n));

        for(int i =0; i<3; i++){
            solve(i, given, preCompute, adj,n);
        }
        
        int count = 0;
        for(int col =0; col<n; col++){
            vector<int> temp;
            for(int row =0; row<3; row++){
                temp.push_back(preCompute[row][col]);

            }

            if(checkPythagorus(temp)){
                count++;
            }
        }

        return count;
        
    }
};