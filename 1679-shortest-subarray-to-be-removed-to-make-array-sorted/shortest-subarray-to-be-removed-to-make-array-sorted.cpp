class Solution {
private:
    bool isPossible(int targetLen, vector<int> &arr, vector<bool> &prefix, vector<bool> &suffix){
        int i =0;
        int n = arr.size();
        for(int j=targetLen-1; j<n; j++){
            bool isValid = true;
            isValid = isValid && (i-1 >=0 ? prefix[i-1] : true);
            if(isValid){
                if(j+1<n && i-1 >=0 && arr[i-1] > arr[j+1]){
                    isValid = false;

                }
            }

            isValid = isValid && (j+1 < n ? suffix[j+1] : true);

            if(isValid) return true;

            i++;


        }

        return false;
    }
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l =0;
        int r = n-1;
        int ans = 0;
        // precompute
        vector<bool> isPrefixSorted(n, false);
        isPrefixSorted[0] = true;
        vector<bool> isSuffixSorted(n, false);
        isSuffixSorted[n-1] = true;

        for(int i=1; i<n; i++){
            if(arr[i] >= arr[i-1]){
                isPrefixSorted[i] = true;
            }else{
                break;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(arr[i+1] >= arr[i]){
                isSuffixSorted[i] = true;
            }else{
                break;
            }
        }


        while(l<=r){
            int mid = l + (r-l)/2;
            if(isPossible(mid,arr, isPrefixSorted, isSuffixSorted)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;

        
    }
};