class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum = accumulate(cardPoints.begin(), cardPoints.begin() + k,0);
        int currSum = maxSum;
        int i = k-1;
        int j =cardPoints.size()-1;
        if(k == cardPoints.size()) return maxSum;
        while(k--){
            currSum = currSum - cardPoints[i--] + cardPoints[j--];
            maxSum = max(currSum, maxSum);

        }
        return maxSum;
        
    }
};