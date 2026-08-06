class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int leftCount = i+1;
            int rightCount = n-i;
            int totalCount = leftCount * rightCount;
            int targetCount = (totalCount + 1)/2;
            int currSum = targetCount * arr[i];
            ans += currSum;
        }
        return ans;
        
    }
};