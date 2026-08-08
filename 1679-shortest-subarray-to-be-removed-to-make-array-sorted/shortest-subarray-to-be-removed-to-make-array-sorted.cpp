class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        // Find the first index of the sorted suffix
        int right = n - 1;

        while (right > 0 && arr[right] >= arr[right - 1]) {
            right--;
        }

        // Delete everything before right
        int ans = right;

        // Keep a sorted prefix [0...i]
        int i = 0;
        int j = right;

        while (i < right) {

            // Prefix [0...i] must remain sorted
            if (i > 0 && arr[i] < arr[i - 1]) {
                break;
            }

            // Move suffix start until it can connect
            while (j < n && arr[j] < arr[i]) {
                j++;
            }

            // Delete [i+1 ... j-1]
            ans = min(ans, j - i - 1);

            i++;
        }

        return ans;
    }
};