class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, 1});
        int globalMaxLen = 0;
        int globalMaxCount = 0;

        for (int i = 0; i < n; i++) {
            int maxLen = 1;
            int maxCount = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    int currLen = dp[j].first;
                    if (currLen + 1 > maxLen) {
                        maxLen = currLen + 1;
                        maxCount = dp[j].second;
                    } else if (currLen + 1 == maxLen) {
                        maxCount += dp[j].second;
                    }
                }
            }

            dp[i] = {maxLen, maxCount};

            if (maxLen > globalMaxLen) {
                globalMaxLen = maxLen;
            }
        }

        // cout<<globalMaxLen<<end;

        for (int i = 0; i < n; i++) {
            if (dp[i].first == globalMaxLen) {
                globalMaxCount += dp[i].second;
            }
        }

        return globalMaxCount;
    }
};