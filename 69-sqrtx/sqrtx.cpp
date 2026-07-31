class Solution {
private:
    int getResult(int mid, int n){
        long long result = 1LL * mid * mid;
        if(result == n){
            return 0;
        }else if(result > n){
            return 1;
        }else{
            return -1;
        }
    }
public:
    int mySqrt(int n) {
        if(n==1) return 1;
        int l = 1;
        int r = n/2 + 1;
        int ans = -1;
        
        while(l<=r){
            int mid = l + ((r-l)/2);
            int result = getResult(mid, n);
            if(result == 0 || result == 1){
                ans = mid -result;
                r = mid-1;
                
            }else{
                l = mid+1;
            }
        }
        return ans;
        
    }
};