class Solution {
private:
    bool isValid(int mid, vector<int>& nums, int h){
        int currHours = 0;
        for(int i = 0; i < nums.size(); i++){
            currHours += ceil( 1.0* nums[i] / mid);
            
            // Early termination optimization
            if(currHours > h) return false;
        }
        return currHours <= h;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;  // Initialize to right instead of 0
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(isValid(mid, piles, h)){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};