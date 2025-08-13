class Solution {
private:
    int solve(int n, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        // If amount is 0, no coins needed
        if (amount == 0) return 0;

        // If no coins left or amount becomes negative
        if (n == 0) return INT_MAX - 1;

        // Base case: only one coin type left
        if (n == 1) {
            if (amount % coins[0] == 0) return amount / coins[0];
            else return INT_MAX - 1;
        }

        if (dp[n][amount] != -1) return dp[n][amount];

        // Don't take current coin
        int noTake = solve(n - 1, amount, coins, dp);

        // Take current coin (stay on same n because unlimited supply)
        int take = INT_MAX;
        if (coins[n - 1] <= amount) {
            take = 1 + solve(n, amount - coins[n - 1], coins, dp);
        }

        return dp[n][amount] = min(take, noTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = solve(n, amount, coins, dp);
        return (ans >= INT_MAX - 1) ? -1 : ans; // -1 if impossible
    }
};
