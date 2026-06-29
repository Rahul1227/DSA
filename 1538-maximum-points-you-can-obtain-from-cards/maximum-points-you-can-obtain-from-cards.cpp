class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(k == n) return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int l = k-1;
        int r = n-1;
        int currSum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int maxSum = currSum;
        while(l >=0){
            currSum = currSum - cardPoints[l--] + cardPoints[r--];
            maxSum = max(maxSum, currSum);

        }

        return maxSum;

        
    }
};