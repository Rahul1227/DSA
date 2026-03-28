class Solution {
private:
    void solve(int node, int parent, int &timer, vector<int> &visited, vector<vector<int>> &adj, vector<int>& firstInsertionTime, vector<int>& adjacentLowestTime, vector<vector<int>> &bridges){

        visited[node] = 1;
        firstInsertionTime[node] = timer++;
        adjacentLowestTime[node] = firstInsertionTime[node];

        for(auto v : adj[node]){
            if(v == parent) continue;

            if(!visited[v]){
                solve(v, node, timer, visited, adj, firstInsertionTime, adjacentLowestTime, bridges);
                adjacentLowestTime[node] = min(adjacentLowestTime[node], adjacentLowestTime[v]);

                if(adjacentLowestTime[v] > firstInsertionTime[node]){
                    bridges.push_back({node, v});
                }
            }else{
                adjacentLowestTime[node] = min(adjacentLowestTime[node], adjacentLowestTime[v]); 
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(int i =0; i< connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n, 0);
        vector<int> firstInsertionTime(n,0);
        vector<int> adjacentLowestTime(n,0);
        vector<vector<int>> bridges;
        int timer = 1;
        // solve(v, node, timer, visited, adj, firstInsertionTime, adjacentLowestTime, bridges);
        solve(0, -1, timer, visited, adj, firstInsertionTime, adjacentLowestTime, bridges);


        return bridges;
    }
};