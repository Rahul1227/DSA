class Solution {
private:
    vector<vector<int>> prefixRow;
    vector<vector<int>> prefixCol;
    bool isValid(int x1, int y1, int x2, int y2, vector<vector<int>> &grid){
        // checking every row
        int rowSum = prefixRow[x1][y2+1] - prefixRow[x1][y1];
        for(int row = x1+1; row <= x2; row++){
            int currRowSum = prefixRow[row][y2+1] - prefixRow[row][y1];
            if(currRowSum != rowSum) return false;
        }

        //checking every col
        int colSum = prefixCol[x2+1][y1] - prefixCol[x1][y1];

        for(int col = y1+1; col<=y2; col++){
            int currColSum = prefixCol[x2+1][col] - prefixCol[x1][col];
            if(currColSum != colSum) return false;
        }

        int i1 = x1;
        int j1 = y1;
        int diaSum1 = 0;
        while(i1<=x2 && j1 <= y2){
            diaSum1 += grid[i1][j1];
            i1++;
            j1++;
        }

        if(diaSum1 != colSum) return false;

        int i2 = x1;
        int j2 = y2;
        int diaSum2 = 0;
        while(i2 <= x2 && j2 >= y1){
            diaSum2 += grid[i2][j2];
            i2++;
            j2--;

        }

        if(diaSum2 != colSum) return false;


        return true;


    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int maxSide = 1;
        int n = grid.size();
        int m = grid[0].size();

        // filling the prefixRow
        prefixRow.resize(n, vector<int>(m+1, 0));
        for(int row =0; row<n; row++){
            for(int col=0; col<m; col++){
                prefixRow[row][col+1] = grid[row][col] + prefixRow[row][col];
            }
        }

        // filling the prefixCol
        prefixCol.resize(n+1, vector<int>(m,0));
        for(int col =0; col<m; col++){
            for(int row =0; row<n; row++){
                prefixCol[row+1][col] = grid[row][col] + prefixCol[row][col];
            }
        }

        // // displaying the result
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<prefixCol[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int side = min(m,n); side >= 2; side --){
            for(int i =0; i + side-1 < n; i++){
                for(int j=0; j+side-1 < m; j++){
                    int k = i+side-1;
                    int l = j+side-1;
                    if(isValid(i,j,k,l,grid)){
                        return side;
                    }


                }

            }
        }


        

        return 1;
    }
};