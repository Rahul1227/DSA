class Solution {
private:
    bool solve(int ind, vector<int> &arr, vector<pair<int,int>> &ranges, vector<int> &visited){
        int n = arr.size();
        if(ind < 0 || ind >= n) return false;
        if(arr[ind] == 0) return true;

        // if(dp[ind] != -1) return dp[ind];

        bool left = false;
        if(ranges[ind].first >= 0 && !visited[ranges[ind].first]){
            visited[ranges[ind].first] = 1;
            left = solve(ranges[ind].first, arr, ranges, visited);
            
           
        }
        bool right = false;
        if(ranges[ind].second <n && !visited[ranges[ind].second]){
            visited[ranges[ind].second] = 1;
            right = solve(ranges[ind].second, arr, ranges, visited);
           
           
        }

        return left || right;
}
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<pair<int,int>> ranges;
        for(int i=0; i<n; i++){
            int left = i - arr[i];
            int right = i+ arr[i];
            ranges.push_back({left, right});
        }
        vector<int> dp(n, 0);

        return solve(start, arr, ranges, dp);
        
    }
};