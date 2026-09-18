class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = INT_MAX / 2;
        vector<int> best(n, INF);   // best[k] = k tak ka sabse chhota valid subarray

        int ans = INF;
        int i = 0;
        int currSum = 0;

        for (int j = 0; j < n; j++) {
            currSum += arr[j];

            while (currSum > target) {
                currSum -= arr[i];
                i++;
            }

            if (j > 0) best[j] = best[j - 1];          // fix 1

            if (currSum == target) {
                int currLen = j - i + 1;

                if (i > 0 && best[i - 1] != INF) {     // fix 2: same INF
                    ans = min(ans, best[i - 1] + currLen);
                }
                best[j] = min(best[j], currLen);       // fix 3 + 4: bahar, aur [j] par
            }
        }

        return ans == INF ? -1 : ans;
    }
};