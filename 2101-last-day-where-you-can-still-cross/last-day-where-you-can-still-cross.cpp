class DisjointSet{
private:
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i =0; i<n; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int u){
        if(parent[u] == u){
            return u;
        }

        return parent[u] = findUltimateParent(parent[u]);
    }



    void unionBySize(int u, int v){
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        if(parentU == parentV) return;

        if(size[parentU] >= size[parentV]){
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }else{
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
    }

    bool isConnected(int u, int v){
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        return parentU == parentV;
    }

};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // 1 ==> water
        // 0 ==> land
        vector<vector<int>> grid(row+1, vector<int>(col+1,1));

        int total = row * col + 3;
        int TOP = row * col + 1;
        int BOTTOM = row * col + 2;

        DisjointSet ds(total);

        int n = cells.size();
        for(int day = n-1; day >=0; day--){
            int currRow = cells[day][0];
            int currCol = cells[day][1];
            grid[currRow][currCol] = 0;
            int currNode = (currRow -1)* col + currCol;
            int dirX[] = {-1,1,0,0};
            int dirY[] = {0,0,1,-1};
            // searching in all the 4 directioons
            for(int i =0; i<4; i++){
                int newRow = currRow + dirX[i];
                int newCol = currCol + dirY[i];
                int newNode = (newRow-1) * col + newCol;
                if(
                    newRow > 0 && newRow <= row &&
                    newCol > 0 && newCol <= col &&
                    grid[newRow][newCol] == 0){
                        ds.unionBySize(currNode, newNode);

                }
            }

            if(currRow == 1){
                ds.unionBySize(currNode, TOP);
            }

            if(currRow == row){
                ds.unionBySize(currNode, BOTTOM);
            }

            if(ds.isConnected(TOP,BOTTOM)){
                return day;
            }

        }

        return 0;
        
    }
};