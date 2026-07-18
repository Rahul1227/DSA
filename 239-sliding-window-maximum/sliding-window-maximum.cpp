class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n = nums.size();

        for(int j =0; j<n; j++){
            //pushing
            while(!dq.empty() && nums[j] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);

            // window reached
            if(j >= k-1){
                // clearning first
                while(!dq.empty() && j - dq.front() + 1 > k){
                    dq.pop_front();
                }

                ans.push_back(nums[dq.front()]);
            }

        }

        return ans;
        
    }
};