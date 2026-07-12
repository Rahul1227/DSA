const int MOD = 1e9+7;
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> diff(100005, 0);
        int minStart = 0;
        int maxEnd = 0;
        for(auto request : requests){
            int start = request[0];
            int end = request[1];
            minStart = min(minStart, start);
            maxEnd = max(end, maxEnd);
            diff[start]++;
            diff[end+1]--;
        }

        vector<int> intersection;
        int curr = 0;
        for(int i=minStart; i<=maxEnd; i++){
            curr += diff[i];
            intersection.push_back(curr);
        }

        sort(intersection.begin(), intersection.end(), greater<>());
        sort(nums.begin(), nums.end(), greater<>());
        long long ans = 0;
        for(int i=0; i<intersection.size(); i++){
            long long curr = (1LL * intersection[i] * nums[i]) % MOD;
            ans = (1LL * ans + curr) % MOD;
        }
        return ans;
    }
};