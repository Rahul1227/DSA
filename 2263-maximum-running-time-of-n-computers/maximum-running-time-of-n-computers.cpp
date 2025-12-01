class Solution {
private:
    bool isPossible(long long val, int n, vector<int> &batteries){
        long long total = 0;
        for(long long x : batteries){
            total += min(x,val);
        }

        return total >= val * n;
    }

public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 1;
        long long ans = 0;
        long long right = accumulate(batteries.begin(), batteries.end(), 0LL) / n;
;
        while(left <= right){
            long long mid = left + ((right - left)/2);
            if(isPossible(mid, n, batteries)){
                ans = mid;
                left = mid + 1;
                
            }else{
                right = mid -  1;
            }
        }

        return ans;
        
    }
};