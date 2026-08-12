class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int ansRow = 0;
        int count =0;

        for(int i=0; i<row; i++){
            int currCount = 0;
            for(int j=0; j<col; j++){
                if(mat[i][j] == 1){
                    currCount++;
                }
            }
            if(currCount > count){
                count = currCount;
                ansRow = i;
            }
        }

        return {ansRow, count};
        
    }
};