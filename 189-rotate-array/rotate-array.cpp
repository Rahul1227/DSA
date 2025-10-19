class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // efficient approach
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() +k, nums.end());





        // vector<int> temp;
        // int n = nums.size();
       
        // k = k % n;
        
        // for(int i =0; i< n-k; i++){
        //     temp.push_back(nums[i]);
        // }

        // //placing the second part in the front
        // int ind = 0;
        // for(int i = n-k; i<n; i++){
        //     nums[ind++] = nums[i];
        // }

        // // now second part
        // for(int i =0; i<temp.size(); i++){
        //     nums[ind++] = temp[i];
        // }
        
    }
};