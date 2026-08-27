class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n = nums.size();

        for(int j=0; j<n; j++){
            // push
            while(!dq.empty() && nums[dq.back()] <= nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);

            if(j-0+1 < k) continue;

            while(!dq.empty() && dq.front() < j-k+1){
                dq.pop_front();
            }

            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};