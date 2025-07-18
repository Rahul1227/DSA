class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // brute force approach
        // int result = 0;
        // for(int i =0; i<nums.size(); i++){
        //     int currSum =0;
        //     for(int j=i; j<nums.size(); j++){
        //         currSum += nums[j];
        //         if(currSum % k == 0){
        //             result ++;

        //         }

        //     }
        // }
        // return result;

        // optimal approach

        int currSum = 0;  // for the prefixSum calculation
        unordered_map<int, int> lookUp; // map to see the remainders
        lookUp[0] = 1;
        int answer = 0; // variable to store the answer
        for( int i =0; i< nums.size(); i++){
            currSum += nums[i];
            int remainder = currSum % k;
            if(remainder < 0){
                remainder = k + remainder;
            }
            if(lookUp.find(remainder) != lookUp.end()){
                answer += lookUp[remainder];
                lookUp[remainder]++;
            }else{
                lookUp[remainder] = 1;
            }

        }
        return answer;
        
    }
};