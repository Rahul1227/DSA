class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int r = row-1;
        int c = 0;

        while(r >=0 && c< col){
            // cout<<r<<" - "<<c<<endl;
            int currEle = matrix[r][c];
            if(currEle == target){
                return true;
            }else if(target < currEle){
                r = r-1;
            }else{
                c = c+1;
            }
        }

        return false;
        
    }
};