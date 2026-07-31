class Solution {
private:
    bool isPossible(int mid, vector<int> & arr, int m, int k){
        int count = 0;
        int i=0;
        int j =0;
        int currFlower = 0;
        int n = arr.size();
        while(j<n){
            if(arr[j] <= mid){
                currFlower++;
            }else{
                currFlower = 0;
                i= j+1;
            }

            if(currFlower == k){
                count++;
                currFlower = 0;
                i = j+1;
            }

            if(count >= m) return true;
            j++;
        }

        return count == m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long possible = 1LL * m * k;
        if(possible > n) return -1;

        int l = 1;
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        
        int ans = r;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(isPossible(mid, bloomDay, m, k)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
        
    }
}; 