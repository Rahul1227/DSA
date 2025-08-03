class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i =0;
        int j = 0;
        int maxlen = 0;
        queue<int> zeroInd;
        
        while(i<n && j<n){
            if(nums[j] != 1){
                zeroInd.push(j);
                if(k > 0){
                    k--;
                }else{
                    i = zeroInd.front() + 1;
                    zeroInd.pop();
                    // k++;
                }


            }
            maxlen = max(maxlen, j-i+1);
            j++;

        }
        return maxlen;
        
    }
};