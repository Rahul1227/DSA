class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        while(!is_sorted(nums.begin(), nums.end())){
            int i =0;
            while(i < n-1 && nums[i] <= nums[i+1]){
                i++;
            }
            int currMinSum = INT_MAX;
            int minInd = -1;

            for(int j =0; j< n-1; j++){
                int sum = nums[j] + nums[j+1];

                if(sum < currMinSum){
                    currMinSum = sum;
                    minInd = j;
                }
            }
            // cout<<"THe minSum"<<currMinSum<<" "<<minInd<<endl;
            nums[minInd] = currMinSum;
            nums.erase(nums.begin() + minInd+1);\
            n--;
            // for(auto num: nums){
            //     cout<<num<<" ";
            // }
            // cout<<endl;
            count++;

        }


        return count;

    }
};