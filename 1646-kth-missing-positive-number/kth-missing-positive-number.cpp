class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        

        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;

            int diff = arr[mid] - (mid+1);
            if(diff >= k){
                r = mid-1;
                
            }else{
                l = mid+1;

            }
        }
        // int more = k - arr[r] - r+1;
        return l + k;

        
    }
};