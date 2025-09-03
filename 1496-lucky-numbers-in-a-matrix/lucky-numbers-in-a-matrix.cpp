class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int,int> mp;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
       
        // Store row minima
        for(int r = 0; r<n; r++){
            int minEle = *min_element(matrix[r].begin(), matrix[r].end());
            mp[minEle] = 1;
        }

        // Check column maxima
        for(int c = 0; c<m; c++){
            int maxEle = 0;
            for(int r =0; r<n; r++){
                maxEle = max(maxEle, matrix[r][c]);  // corrected indexing
            }
            if(mp.find(maxEle) != mp.end()){
                ans.push_back(maxEle);
            }
        }
        return ans;
    }
};
