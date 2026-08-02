class Solution {
private:
    int solve(int Alice, int i,int m, vector<vector<vector<int>>> &dp, vector<int> &piles){
        int n = piles.size();
        if(i >= n){
            return 0;
        }

        if(dp[Alice][i][m] != -1) return dp[Alice][i][m];

        int ans = Alice ? INT_MIN : INT_MAX;
        int currStones = 0;
        int leftElements = n - i;
        for(int offset = 1; offset <=min(2*m, leftElements); offset++){
            currStones += piles[i+offset-1];
            if(Alice){
                ans = max(ans, currStones + solve(0, i+offset, max(m, offset), dp,piles));
            }else{
                ans = min(ans, solve(1, i+offset, max(m, offset), dp, piles));
            }
        }

        return dp[Alice][i][m] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1,vector<int>(n+1, -1)));
       
       
        return solve(1,0,1, dp, piles);
        
    }
};