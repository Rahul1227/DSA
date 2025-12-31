class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // ✅ FIX #1: Each node is its own parent
        }
    }

    int findUltimateParent(int u) {
        if (parent[u] == u) {
            return u;
        }
        // Path compression
        return parent[u] = findUltimateParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);

        if (ultimateParentU == ultimateParentV)
            return;

        // Union by size: attach smaller to larger
        if (size[ultimateParentU] <= size[ultimateParentV]) {
            parent[ultimateParentU] = ultimateParentV;
            size[ultimateParentV] += size[ultimateParentU];
        } else {
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU] += size[ultimateParentV];
        }
    }

    bool isConnected(int u, int v) {
        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);
        return ultimateParentU == ultimateParentV;
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // Virtual nodes for TOP and BOTTOM
        int TOP = row * col;
        int BOTTOM = row * col + 1;
        DisjointSet ds(row * col + 2);  // +2 for TOP and BOTTOM

        // 1 => water, 0 => land
        vector<vector<int>> grid(row + 1, vector<int>(col + 1, 1));

        int n = cells.size();
        
        // Go backward through days
        for (int days = n - 1; days >= 0; days--) {
            int r = cells[days][0];
            int c = cells[days][1];

            // Expose this cell as land
            grid[r][c] = 0;
            
            // ✅ FIX #3: Convert 1-indexed (r,c) to 0-indexed DSU node
            int currCell = (r - 1) * col + (c - 1);

            // Check all 4 neighbors
            int dirX[] = {-1, 1, 0, 0};
            int dirY[] = {0, 0, 1, -1};
            
            for (int i = 0; i < 4; i++) {
                int newR = r + dirX[i];
                int newC = c + dirY[i];

                // If neighbor is valid and is land
                if (newR >= 1 && newR <= row && newC >= 1 && newC <= col &&
                    grid[newR][newC] == 0) {
                    
                    // ✅ FIX #2: Calculate neighbor index correctly
                    int newCell = (newR - 1) * col + (newC - 1);
                    
                    // ✅ FIX #2: Use newCell, not newC
                    ds.unionBySize(currCell, newCell);
                }
            }

            // Connect to TOP virtual node if in first row
            if (r == 1) {
                ds.unionBySize(currCell, TOP);
            }

            // Connect to BOTTOM virtual node if in last row
            if (r == row) {
                ds.unionBySize(currCell, BOTTOM);
            }

            // Check if TOP and BOTTOM are connected
            if (ds.isConnected(TOP, BOTTOM)) {
                return days;
            }
        }
        
        return 0;
    }
};

/*
BUGS FIXED:

1. ❌ parent[i] = 1  →  ✅ parent[i] = i
   - Was connecting all nodes to node 1 initially
   - Now each node is its own parent (isolated)

2. ❌ ds.unionBySize(currCeil, newC)  →  ✅ ds.unionBySize(currCell, newCell)
   - Was using column number instead of cell index
   - Now uses correctly calculated cell index

3. ❌ (r-1)*col + c  →  ✅ (r-1)*col + (c-1)
   - Was off-by-one in index calculation
   - Now correctly converts 1-indexed to 0-indexed

TIME COMPLEXITY: O(row × col × α(n)) ≈ O(row × col)
SPACE COMPLEXITY: O(row × col)
*/