class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int u) {
        if (parent[u] == u) {
            return u;
        }

        return parent[u] = findUltimateParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);

        if (ultimateParentU == ultimateParentV)
            return;

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
        int TOP = row * col + 1;
        int BOTTOM = row * col + 2;
        DisjointSet ds(row * col + 3);

        // 1==> water , 0 ==> land
        vector<vector<int>> grid(row + 1, vector<int>(col + 1, 1));

        int n = cells.size();
        for (int days = n - 1; days >= 0; days--) {
            int r = cells[days][0];
            int c = cells[days][1];

            grid[r][c] = 0;
            int currCeil = (r - 1) * col + c;

            int dirX[] = {-1, 1, 0, 0};
            int dirY[] = {0, 0, 1, -1};
            for (int i = 0; i < 4; i++) {
                int newR = r + dirX[i];
                int newC = c + dirY[i];

                if (newR >= 1 && newR <= row && newC >= 1 && newC <= col &&
                    grid[newR][newC] == 0) {
                    int newCeil = (newR - 1) * col + newC;
                    ds.unionBySize(currCeil, newCeil);
                }
            }

            // connect to the top
            if (r == 1) {
                ds.unionBySize(currCeil, TOP);
            }

            // connect to the bottom
            if (r == row) {
                ds.unionBySize(currCeil, BOTTOM);
            }

            // check if top and bottom are connect
            if (ds.isConnected(TOP, BOTTOM)) {
                return days;
            }
        }
        return 0;
    }
};