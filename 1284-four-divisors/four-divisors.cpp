class Solution {
private:
    int solve(int &num){
        vector<int> divisors;
        for(int i =1; i<=num; i++){
            if(num % i == 0){
                divisors.push_back(i);
                if(divisors.size()> 4) return 0;
            }
        }
        if(divisors.size() == 4){
            return accumulate(divisors.begin(), divisors.end(),0);
        }else{
            return 0;
        }
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto num : nums){
            if(mp.count(num)){
                ans += mp[num];
                continue;
            }
            int result =solve(num);
            mp[num] = result;
            ans += result;
        }
        return ans;
        
    }
};