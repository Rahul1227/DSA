class Solution {
private:
    int getCount(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int i =0;
        int j =0;
        int n = nums.size();
        int ans =0;
        int sum =0;
        while(j<n){
            sum += nums[j];
            while(sum > goal){
                sum -= nums[i];
                i++;
            }
            if(sum <= goal){
                ans +=(j-i+1);
            }
            j++;

        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& arr, int goal) {
        // return getCount(nums, goal) - getCount(nums, goal-1);
        int ans = 0;
        unordered_map<int,int> mp;
        mp[0] =1;
        int currSum =0;
        for(int i=0; i<arr.size(); i++){
            currSum += arr[i];
            int req = currSum - goal;
            if(mp.count(req)){
                ans += mp[req];
            }
            
            
            
            mp[currSum]++;
        }
        return ans;
    }
    
};