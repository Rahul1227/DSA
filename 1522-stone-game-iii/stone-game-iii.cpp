class Solution {
private:
    int solve(int Alice, int ind, vector<vector<int>> &dp, vector<int> &arr){
        int n = arr.size();
        if(ind >= n){
            return 0;
        }

        if(dp[Alice][ind] != -1) return dp[Alice][ind];
        int ans = Alice ? INT_MIN : INT_MAX;
        int currStones = 0;

        for(int i = 1; i<= min(3, n-ind); i++){
            currStones += arr[ind+i-1];
            if(Alice){
                ans = max(ans, currStones + solve(0, ind+i, dp,arr));
            }else{
                ans = min(ans, solve(1, ind+i, dp, arr));
            }

        }

        return dp[Alice][ind] = ans;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(2, vector<int>(n+1, -1));
        int AliceScore = solve(1, 0,dp, stoneValue);
        int totalScore = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        int BobScore = totalScore - AliceScore;
        cout<<AliceScore<<endl;

        if(AliceScore > BobScore){
            return "Alice";
        }else if(AliceScore < BobScore){
            return "Bob";
        }else{
            return "Tie";
        }
        
    }
};