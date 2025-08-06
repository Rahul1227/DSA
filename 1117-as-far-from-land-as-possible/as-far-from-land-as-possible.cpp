class Solution {
public:
     int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        
        // Add all land cells to queue and mark them as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        
        // Edge cases: no land or no water
        if (q.empty() || q.size() == n * n) {
            return -1;
        }
        
        // Directions for 4-connected neighbors
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int maxDist = 0;
        
        // Multi-source BFS
        while (!q.empty()) {
            int size = q.size();
            
            // Process all cells at current distance level
            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();
                
                // Explore all 4 neighbors
                for (auto [dr, dc] : directions) {
                    int newRow = row + dr;
                    int newCol = col + dc;
                    
                    // Check bounds and if cell is water (unvisited)
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && 
                        grid[newRow][newCol] == 0) {
                        
                        // Mark as visited by setting to 1
                        grid[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
            
            // If queue is not empty, we processed another distance level
            if (!q.empty()) {
                maxDist++;
            }
        }
        
        return maxDist;
    }
};