class Solution {
private:
    long long getCount(vector<int> &nums, int k){
        if(k == 0) return 0;
        int i =0;
        int j =0;
        int n = nums.size();
        unordered_map<int,int> mp;
        long long ans =0LL;
        while(j < n){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            if(mp.size() <= k){
                // cout<<"Inside the loop"<<endl;
                ans += 1LL *j - i + 1;
            }
            j++;
        }
        // cout<<ans<<endl;
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return getCount(nums, k) - getCount(nums, k-1);
        
    }
};