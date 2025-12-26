class Solution {
private:
    int quickSort(int left, int right, vector<int>& nums) {
        int partitionValue = nums[left];
        int i = left;
        int j = right;
        while (i <= j) {
            if (nums[i] < partitionValue && nums[j] > partitionValue ) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }

            if (nums[i] >=  partitionValue) {
                i++;
            }

            if (nums[j] <= partitionValue) {
                j--;
            }
        }

        swap(nums[left], nums[j]);
        return j;
    }

    int solve(int left, int right, vector<int>& nums, int k) {
        if (left == right)
            return nums[left];

        int partitionInd = quickSort(left, right, nums);
        if (partitionInd == k - 1) {
            return nums[partitionInd];
        } else if (partitionInd > k - 1) {
            return solve(left, partitionInd - 1, nums, k);
        } else {
            return solve(partitionInd + 1, right, nums, k);
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return solve(0, n - 1, nums, k);
    }
};