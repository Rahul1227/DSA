class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // creating a weighted adjacency matrix
        vector<vector<int>> adjMat(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adjMat[u][v] = w;
            adjMat[v][u] = w;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adjMat[i][k] != INT_MAX / 2 &&
                        adjMat[k][j] != INT_MAX / 2) {
                        adjMat[i][j] =
                            min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]

                            );
                    }
                }
            }
        }

        int minNeigh = INT_MAX;
        int minInd = -1;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if(i == j) continue;
                if (adjMat[i][j] <= distanceThreshold){
                    // cout<<"count is called for "<<i<<endl;
                    count++;
                }
                    
            }
            if (count <= minNeigh) {
                minNeigh = count;
                minInd = i;
            }
        }

        return minInd;
    }
};