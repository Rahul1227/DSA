class Solution {
private:
    long long solve(int l,  int r, int pos, int rem, vector<int> &req, vector<vector<vector<long long>>> &dp){
        //base case
        int n = req.size();
        if(rem == 0){
            return 0;
        }

        if(dp[l][r][pos] != -1){
            return dp[l][r][pos];
        }

        long long ans = LLONG_MAX/4;

        if(pos){
            // current at r
            if(r+1 < n){
                int dist = req[r+1] - req[r];
                ans = min(ans, 1LL *dist * rem + solve(l, r+1, 1, rem-1, req, dp));
            }
            if(l-1 >=0){
                int dist =req[r] - req[l-1];
                ans = min(ans, 1LL * dist * rem + solve(l-1, r, 0, rem-1, req, dp));
            }
        }else{
            // current at l
            if(r+1 < n){
                int dist = req[r+1] - req[l];
                ans = min(ans, 1LL * dist * rem + solve(l, r+1, 1, rem-1, req, dp));
            }
            if(l-1 >=0){
                int dist = req[l] - req[l-1];
                ans = min(ans, 1LL * dist * rem + solve(l-1, r, 0, rem-1, req, dp));
            }

        }

        return dp[l][r][pos] = ans;

    }
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        // all this just to make sure start is in the req array
        vector<int> req;
        for(auto num: requests){
            if(num != start){
                req.push_back(num);
            }
        }
        req.push_back(start);
        int m = req.size();

        sort(req.begin(), req.end());
        int rem = m-1; // start is not considered
        if(rem == 0){
            return 0;
        }

        vector<vector<vector<long long>>> dp(m+1, vector<vector<long long>>(m+1, vector<long long>(2, -1)));

        int ind = lower_bound(req.begin(), req.end(), start) - req.begin();

        long long ans = solve(ind, ind, 1,rem, req, dp);
        // ans = min(ans, solve(ind, ind, 0, rem, req, dp));
        return ans;


        
    }
};