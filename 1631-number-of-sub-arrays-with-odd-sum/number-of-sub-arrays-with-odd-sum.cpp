const int MOD = 1e9+7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n+1, 0);

        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + arr[i];
        }
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto num: prefix){
            int currParity = num % 2;
            int need = 1 - currParity;
            ans = (ans + mp[need]) % MOD;

            mp[currParity] = (mp[currParity] + 1) % MOD;
        }

        return ans;
        
    }
};