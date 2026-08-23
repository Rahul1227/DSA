class Solution {
public:
    vector<int> isPrime;
    
    void getPrime(){
        isPrime[0] = 0;
        isPrime[1] = 0;
        int n = isPrime.size();
        for(long long i=2*1LL; i<n; i++){
            if(isPrime[i]){
                for(long long j=1LL * i*i; j<n; j=j+i){
                    isPrime[j] = 0;
                }
            }

        }
    }


    vector<int> getFact(int num){
        // int n = isPrime.size();
        vector<int> ans;

        for(int i=2*1LL; i <= num; i++){
            if(isPrime[i]){
                if(num % i == 0){
                    ans.push_back(i);
                    while(num && num % i == 0){
                        num /=i;
                    }
                }
            }
            if(!num){
                break;
            }
        }

        return ans;

    }


    int longestSubarray(vector<int>& nums, int k) {
        int maxEle = *max_element(nums.begin(), nums.end());
        isPrime.assign(maxEle+5, 1);
        getPrime();

        unordered_map<int, vector<int>> arr;
        for(auto num : nums){
            if(!arr.count(num)){
                vector<int> temp = getFact(num);
                arr[num] = temp;
            }
            
        }


        int maxLen =0;
        unordered_map<int,int> mp;
        int i=0;
        int n = nums.size();
        int j =0;

        while(j<n){
            for(auto num: arr[nums[j]]){
                mp[num]++;
            }

            while(i<j && mp.size() > k){
                for(auto num: arr[nums[i]]){
                    mp[num]--;
                    if(mp[num] == 0){
                        mp.erase(num);
                    }
                }
                i++;
            }

            if(mp.size() <= k)
                maxLen = max(maxLen, j-i+1);
            
            j++;


        }


        return maxLen;
        
    }
};