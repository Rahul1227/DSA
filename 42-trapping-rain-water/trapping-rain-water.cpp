class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;
        while(left < right){
            if(height[left] <= height[right]){
                if(height[left] < leftMax){
                    ans += leftMax - height[left];
                }else{
                    leftMax = height[left];
                }
                left++;
            }else{
                if(height[right] < rightMax){
                    ans += rightMax - height[right];
                }else{
                    rightMax = height[right];
                }
                right--;
            }

        }
        return ans;
        
    }
};