class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int originalK = k;
        int n = arr.size();
        k -= arr[0] - 1;
        if(k <= 0) return originalK;

        for(int i = 1; i<n; i++){
            int diff = arr[i] - arr[i-1]-1;
            if(k - diff > 0){
                k -= diff;
            }else{
                return arr[i-1] + k;
            }
        }

        return arr[n-1] + k;

        
    }
};