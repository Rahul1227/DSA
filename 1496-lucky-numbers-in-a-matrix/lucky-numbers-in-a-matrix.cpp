class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        map<int, int> mp;
        int n = matrix.size();
        int m = matrix[0].size();

        // storing the minElements first
        for(int r=0; r<n; r++){
            int minEle = *min_element(matrix[r].begin(), matrix[r].end());
            mp[minEle] = 1;
        }

        //checking for the largest element in the column
        vector<int> ans;
        for(int c=0;  c<m; c++){
            int maxEle =0;
            for(int r=0; r<n; r++){
                maxEle = max(maxEle, matrix[r][c]);
            }

            if(mp.find(maxEle) != mp.end()){
                ans.push_back(maxEle);
            }
        }

        return ans;
        
    }
};