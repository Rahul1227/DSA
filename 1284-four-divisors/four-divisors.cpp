class Solution {
private:
    void preCompute(int maxElement, vector<int> &count, vector<long long>&sum){
        for(int i = 2; i<= maxElement; i++){
            for(int j =i; j<= maxElement; j = j + i){
                count[j]++;
                sum[j] += i;
            }
        }

    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> count(maxElement+1,1);
        vector<long long> sum(maxElement+1, 1);
       
        preCompute(maxElement, count, sum);

        int ans = 0;
        for(auto num : nums){
            if(count[num] == 4){
                ans += (int)sum[num];
            }
        }

        return ans;

        
    }
};