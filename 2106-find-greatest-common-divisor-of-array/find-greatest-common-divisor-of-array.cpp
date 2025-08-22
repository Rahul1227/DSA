class Solution {
public:
    int findGCD(vector<int>& nums) {
        int answer = 1;
        int n = nums.size();
        int minEle = *min_element(nums.begin(), nums.end());
        int maxEle = *max_element(nums.begin(), nums.end());
        // cout<<minEle<<maxEle;
        for(int i = minEle; i>0; i--){
            if((minEle%i == 0) && (maxEle%i == 0)){
                answer = i;
                break;
            }
        }


        return answer;
        
    }
};