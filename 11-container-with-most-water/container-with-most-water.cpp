class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int n = height.size();
        int i =0;
        int j = n-1;
        while(i < j){
            int effectiveHeight = min(height[i], height[j]);
            maxWater = max(maxWater, effectiveHeight * (j-i));
            if(height[i] <= height[j]){
                i++;
            }else{
                j--;
            }

        }
        return maxWater;
        
    }
};