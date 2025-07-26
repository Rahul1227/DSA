class Solution {
public:
    void calculatePermutation(int n, vector<int> &nums, vector<int> &currArray, vector<vector<int>> &result, unordered_map<int, bool> &used) {
        if(currArray.size() == n) {
            result.push_back(currArray);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!used[nums[i]]) {
                currArray.push_back(nums[i]);
                used[nums[i]] = true;

                calculatePermutation(n, nums, currArray, result, used);

                currArray.pop_back();
                used[nums[i]] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> answer;
        vector<int> currArray;
        unordered_map<int, bool> used;

        calculatePermutation(n, nums, currArray, answer, used);
        return answer;
    }
};
