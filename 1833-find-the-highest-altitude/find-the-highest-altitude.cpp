class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlti = 0;
        int currSum = 0;
        for(int num : gain){
            currSum += num;
            maxAlti = max(maxAlti, currSum);
        }

        return maxAlti;
        
    }
};