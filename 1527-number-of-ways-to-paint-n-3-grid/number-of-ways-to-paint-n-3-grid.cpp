class Solution {
    const int MOD = 1e9 + 7;
public:
    int numOfWays(int n) {
        long long one = 6;  // ABA patterns
        long long two = 6;  // ABC patterns

        for(int i = 2; i <= n; i++){
            long long newOne = (2 * one + 2 * two) % MOD;
            long long newTwo = (2 * one + 3 * two) % MOD;
            one = newOne;
            two = newTwo;
        }

        return (one + two) % MOD;
    }
};
