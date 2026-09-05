class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int globalMaxInd = 0;
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        for(int i=0; i<n; i++){
            int maxLen = 1;
            int maxInd = -1;
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] != 0) continue;
                if(dp[j] + 1 > maxLen){
                    maxLen = dp[j] + 1;
                    maxInd = j;
                }
            }
            dp[i] = maxLen;
            parent[i] = maxInd;
            if(maxLen > dp[globalMaxInd]){
                globalMaxInd = i;
            }
        }

        vector<int> ans;
        int maxLen = dp[globalMaxInd];
        while(maxLen--){
            ans.push_back(nums[globalMaxInd]);
            globalMaxInd = parent[globalMaxInd];
        }

        return ans;
        
    }
};