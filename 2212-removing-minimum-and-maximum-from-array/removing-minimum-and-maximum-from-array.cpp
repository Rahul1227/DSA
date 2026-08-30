class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto maxInd = max_element(nums.begin(), nums.end()) - nums.begin();
        auto minInd = min_element(nums.begin(), nums.end()) - nums.begin();
        int n = nums.size();
        int maxBoth = max(maxInd, minInd);
        int minBoth = min(maxInd, minInd);

        int deleteBoth = minBoth + (n - maxBoth);
        // int deleteOtherSide = ()
        cout<<maxBoth<<" "<<deleteBoth<<endl;

        return min({maxBoth+1, deleteBoth+1, n-minBoth});

        


    }
};