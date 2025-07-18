class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute force approach
        // int result = 0;
        // for(int i=0; i<nums.size(); i++){
        //     int currSum = 0;
        //     for(int j = i; j<nums.size(); j++){
        //         currSum += nums[j];
        //         if(currSum == k){
        //             result++;
        //         }

        //     }
        // }
        // return result;


        // trying the optimal approach
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        unordered_map<int, int> lookUp;
        lookUp[0] = 1;
        int answer = 0;
        for(int i =0; i< nums.size(); i++){
            prefix[i+1] =  prefix[i] + nums[i];
            int left = prefix[i+1] - k;
            if(lookUp.find(left) != lookUp.end()){
                answer += lookUp[left];
            }

            lookUp[prefix[i+1]]++;
        }
        return answer;
        
    }
};