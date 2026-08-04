class Solution {
public:
    // ind, prevInd, len, flag
    int dp[1005][1005][5][2];

    int solve(int ind, int prevInd, int len, int inc, vector<int> &rating){
        if(len == 0){
            return 1;
        }

        if(ind == rating.size()){
            return 0;
        }

        if(dp[ind][prevInd+1][len][inc] != -1) return dp[ind][prevInd+1][len][inc];

        int take = 0;
        if(len > 0){
            if(inc){
                if(prevInd == -1 || rating[ind] > rating[prevInd]){
                    take = solve(ind+1, ind, len-1,inc,rating);
                }
            }else{
                if(prevInd == -1 || rating[ind] < rating[prevInd]){
                    take = solve(ind+1, ind, len-1, inc, rating);
                }
            }
        }

        int noTake = solve(ind+1, prevInd, len, inc, rating);



        return dp[ind][prevInd+1][len][inc] = take + noTake;
    }

    int numTeams(vector<int>& rating) {
        memset(dp, -1, sizeof(dp));
        int sum1 = solve(0,-1,3,1,rating);
        int sum2 = solve(0,-1,3,0,rating);
        return sum1 + sum2;

        
        
    }
};