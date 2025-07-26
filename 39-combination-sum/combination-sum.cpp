class Solution {
public:
    void getCombination(int ind, int n, int target, vector<int>& nums, 
                        vector<int>& currArray, vector<vector<int>>& finalResult) {
        if (ind >= n) {
            if (target == 0) {
                finalResult.push_back(currArray);
            }
            return;
        }

        // Take the current element (can reuse the same element)
        if (nums[ind] <= target) {
            currArray.push_back(nums[ind]);
            getCombination(ind, n, target - nums[ind], nums, currArray, finalResult);
            currArray.pop_back(); // backtrack properly here
        }

        // Not take the current element
        getCombination(ind + 1, n, target, nums, currArray, finalResult);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currArray;
        vector<vector<int>> finalResult;
        getCombination(0, candidates.size(), target, candidates, currArray, finalResult);
        return finalResult;
    }
};
