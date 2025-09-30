class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        
        for(int i = 0; i<n; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }else if(sum > 0){
                    k--;
                }else{
                    j++;
                }

            }
        }

        return vector<vector<int>>(st.begin(), st.end());
        
        
    }
};