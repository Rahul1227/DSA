class Solution {
private:
    bool isPossible(int divisor, int threshold, vector<int> &nums){
        int counter = 0;
        for(int i = 0; i< nums.size(); i++){
            counter += nums[i]/divisor;
            if(nums[i] % divisor > 0){
                counter++;
            }

            if(counter > threshold) return false;
        }
        return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = 1;
        while(left <= right){
            int mid = left + ((right - left)/2);
            if(isPossible(mid,threshold,nums)){
                ans = mid;
                right = mid - 1;

            }else{
                left = mid + 1;

            }
        }
        return ans;
        
    }
};