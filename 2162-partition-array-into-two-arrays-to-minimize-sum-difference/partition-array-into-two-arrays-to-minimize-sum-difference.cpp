class Solution {
private:
    vector<vector<long long>> getSubsetSum(vector<int>& nums, int n,
                                           int offset) {
        vector<vector<long long>> ans(n + 1);
        for (int mask = 0; mask < (1 << n); mask++) {
            long long currSum = 0;
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    count++;
                    currSum += 1LL * nums[i + offset];
                }
            }
            ans[count].push_back(currSum);
        }
        // for(int i =0; i< ans.size(); i++){
        //     cout<<i<<" -> ";
        //     for(int j =0; j< ans[i].size(); j++){
        //         cout<<ans[i][j]<<" ";
        //     }
        // }
        // cout << endl;
        return ans;
    }

public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int n1 = n / 2;
        int n2 = n - (n / 2);

        vector<vector<long long>> subSetsum1 = getSubsetSum(nums, n1, 0);
        vector<vector<long long>> subSetsum2 = getSubsetSum(nums, n2, n1);

        for (int i = 0; i < subSetsum2.size(); i++) {
            sort(subSetsum2[i].begin(), subSetsum2[i].end());
        }
        int required = nums.size() / 2;
        int ans = INT_MAX;
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);

        for (int i = 0; i < subSetsum1.size(); i++) {
            for (int j = 0; j < subSetsum1[i].size(); j++) {
                int currReq = required - i;
                if (currReq < 0 || currReq >= subSetsum2.size())
                    continue;

                long long a = subSetsum1[i][j];
                long long b = (totalSum - 2 * a) / 2; // ideal complement sum

                auto& v = subSetsum2[currReq];
                auto itr = lower_bound(v.begin(), v.end(), b);

                if (itr != v.end()) {
                    ans = min(ans, (int)llabs(totalSum - 2 * (a + *itr)));
                }
                if (itr != v.begin()) {
                    long long prevVal = *prev(itr);
                    ans = min(ans, (int)llabs(totalSum - 2 * (a + prevVal)));
                }
            }
        }

        return ans;

        
    }
};