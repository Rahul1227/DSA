class DisjointSet{
private:   
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n){
        parent.assign(n,0);
        size.assign(n, 1);
        for(int i=0; i<n; i++){
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


    vector<int> getParent(){
        for(int i =0; i<parent.size(); i++){
            parent[i] = findUltimateParent(i);
        }
        return parent;
    }

    vector<int> getSize(){
        return size;
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        int dirX[] = {0,0,1,-1};
        int dirY[] = {-1,1,0,0};

        for(int i = 0; i<n; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j] == 0) continue;
                int curr = i * n  + j;
                for(int z =0; z<4; z++){
                    int newR = i + dirX[z];
                    int newC = j + dirY[z];
                    if(newR >=0 && newR < n && newC >=0 && newC < n && grid[newR][newC] == 1){
                        int next = newR * n + newC;
                        ds.unionBySize(curr, next);
                    
                    } 

                }
                
            }
        }

        vector<int> parent = ds.getParent();
        vector<int> size = ds.getSize();
        // int dirX[] = {0,0,1,-1};
        // int dirY[] = {-1,1,0,0};
        int maxSize = *max_element(size.begin(), size.end());
        // cout<<"Before"<<maxSize;
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j] == 1) continue;
                unordered_set<int> taken;
                int currSize = 1;
                for(int z =0; z<4; z++){
                    int newR = i + dirX[z];
                    int newC = j + dirY[z];
                    if(newR >=0 && newR < n && newC >=0 && newC < n && grid[newR][newC] == 1){
                        int curr = newR * n + newC;
                        int par = parent[curr];
                        if(!taken.count(par)){
                            currSize += size[par];
                            taken.insert(par);
                        }
                    
                    } 

                }

                maxSize = max(maxSize, currSize);
                

            }
        }

        return maxSize;
        
    }
};