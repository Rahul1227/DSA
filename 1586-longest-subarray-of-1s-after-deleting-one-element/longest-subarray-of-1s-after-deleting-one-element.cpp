class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxSize = 0;
        int i = 0, j = 0;
        bool canChange = true;

        while (j < n) {
            if (nums[j] == 0) {
                if (canChange) {
                    canChange = false;
                } else {
                    maxSize = max(maxSize, j - i);
                    while (nums[i] != 0) {
                        i++;
                    }
                    i++; // skip the zero
                }
            }
            j++;
        }

        maxSize = max(maxSize, j - i); // check last window
        return maxSize - 1; // must delete exactly one element
    }
};
