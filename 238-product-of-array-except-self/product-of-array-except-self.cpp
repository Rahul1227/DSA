class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector <int> prefixSum(length);
        vector <int> suffixSum(length);
        vector <int> answer(length);
        //calculating prefix sum
        prefixSum[0]=1;
        for(int i = 0; i<length-1; i++){
            prefixSum[i+1] = nums[i] * prefixSum[i];
           

        }
        

        // calculating suffix sum
        suffixSum[length-1] = 1;
        for(int i = length-1; i>0; i--){
            suffixSum[i-1] = nums[i] * suffixSum[i];
            cout << suffixSum[i]<<" ";
        }
        

        // calculating the sum
        for(int i=0; i<length ; i++){
            answer[i] =  prefixSum[i] * suffixSum[i];
        }

        return answer;

        
    }
    
};