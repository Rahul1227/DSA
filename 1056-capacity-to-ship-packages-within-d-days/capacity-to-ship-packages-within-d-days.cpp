class Solution {
private:
    bool isPossible(int mid, vector<int> &weights, int days){
        int currWeight =0;
        int currDays = 1;

        for(int i=0; i< weights.size(); i++){
            // if(currWeight > mid) return false;
            if(currWeight + weights[i] <= mid){
                currWeight += weights[i];
            }else{
                currWeight = weights[i];
                currDays++;
            }

            if(currDays > days){
                return false;
            }
        }

        return currDays <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        int ans = -1;
        while(l<=r){
            int mid = l + ((r-l)/2);

            if(isPossible(mid, weights, days)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
        
    }
};