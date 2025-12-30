class Solution {
private:
    bool isValid(int x, int y, vector<vector<int>> &grid){
        int sum = -1;
        unordered_set<int> st;
        // row wise sum
        for(int i = x; i< x+3; i++){
            int currSum = 0;
            for(int j = y; j< y+3; j++){
                int digit = grid[i][j];
                if(digit > 9 || digit < 1) return false;
                if(st.count(digit)) return false;
                st.insert(digit);
                currSum += digit;

            }

            if(sum == -1){
                sum = currSum;
            }

            if(sum != currSum) return false;
        }

        // col wise sum
        for(int col = y; col < y+3; col++){
            int currSum =0;
            for(int row = x; row < x+3; row++){
                currSum += grid[row][col];
            }

            if(currSum != sum) return false;
        }



        //diagonals
        //diagonal1
        int i = x;
        int j = y;
        int count = 3;
        int diaSum1 = 0;
        while(count--){
            diaSum1 += grid[i][j];
            i++;
            j++;

        }

        if(diaSum1 != sum) return false;

        //diagonal2
        int i2 = x;
        int j2 = y+2;
        int count2 = 3;
        int diaSum2 = 0;
        while(count2--){
            diaSum2 += grid[i2][j2];
            i2++;
            j2--;

        }

        if(diaSum2 != sum) return false;




        return true;
        
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        if(n<3 || m<3) return 0;
        for(int i =0; i<=n-3; i++){
            for(int j =0; j<=m-3; j++){
                if(isValid(i,j,grid)){
                    count++;
                }
            }
        }

        return count;
        
    }
};