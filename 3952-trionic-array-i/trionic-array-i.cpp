class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4)
            return false;
        // int count = 0;
        int i = 1;
        if (i<n && nums[i] > nums[i - 1]) {
            while (i<n && nums[i] > nums[i - 1]) {
                i++;
            }
        } else {
            return false;
        }
        if (i<n && nums[i] < nums[i - 1]) {
            while ( i < n && nums[i] < nums[i - 1]) {
                i++;
            }
        } else {
            return false;
        }

        if (i < n && nums[i] > nums[i - 1]) {
            while (i<n && nums[i] > nums[i - 1]) {
                i++;
            }
        } else {
            return false;
        }

        if (i == n)
            return true;

        return false;
    }
};