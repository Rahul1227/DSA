class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ans = 0;
        int n = arr.size();
        int currSum = 0;
        for(int i =0; i<n; i++){
            currSum += arr[i];
            int rem = currSum % k;
            if(rem < 0){
                rem += k;
            }
            if(mp.count(rem)){
                ans += mp[rem];
            }
            
            mp[rem]++;
        }
        return ans;
        
    }
};