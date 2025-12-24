class Solution {
private:
    int solve(int ind, int prevInd, vector<string>& strs, vector<vector<int>> &dp) {
        if (ind == strs[0].size())
            return 0;

        if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];

        int notTake = solve(ind+1, prevInd, strs,dp);

        int take = 0;
        bool flag = true;
        if (prevInd != -1) {
            for (int i = 0; i < strs.size(); i++) {
                if (strs[i][prevInd] > strs[i][ind]) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            take = 1 + solve(ind + 1, ind, strs, dp);
        }

        return dp[ind][prevInd+1] = max(take, notTake);
    }

public:
    int minDeletionSize(vector<string>& strs) {
        int wordLen = strs[0].size();
        vector<vector<int>> dp(wordLen, vector<int>(wordLen+1, -1));
        int lenLIS = solve(0, -1, strs, dp);
        cout<<lenLIS;
        return wordLen - lenLIS;
    }
};