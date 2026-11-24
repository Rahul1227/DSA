class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i=1; i<=numRows; i++){
            vector<int> temp(i, 1);
            if(i>2){
                for(int j = 1; j<i-1; j++){
                    temp[j] = ans[i-2][j-1] + ans[i-2][j];
                }
            }
            ans[i-1] = temp;
        }


        return ans;
        
    }
};