class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> dp(n, {1,1});

        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[j] < nums[i]){
                    if(dp[j].first + 1 == dp[i].first){
                        dp[i].second += dp[j].second;
                    }else if(dp[j].first +1 > dp[i].first){
                        dp[i].first = dp[j].first+1;
                        dp[i].second = dp[j].second;
                    }
                }
            }
        }

        int maxLen = 1;
        int maxCount = 0;

        for(int i=0; i<n; i++){
            if(dp[i].first > maxLen){
                maxLen = dp[i].first;
                maxCount = dp[i].second;
            }else if(dp[i].first == maxLen){
                maxCount += dp[i].second;
            }
        }

        return maxCount;
        
    }
};