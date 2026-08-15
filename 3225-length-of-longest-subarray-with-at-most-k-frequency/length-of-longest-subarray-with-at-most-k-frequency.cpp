class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxLen = 0;
        int n = nums.size();
        int count = 0;
        int i=0;
        int j =0;
        unordered_map<int,int> freq;

        while(j<n){
            freq[nums[j]]++;
            if(freq[nums[j]] > k){
                count++;
            }

            while(count){
                freq[nums[i]]--;
                if(freq[nums[i]] == k){
                    count--;
                }
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;

        }

        return maxLen;
        
    }
};