class Solution {
private:
    bool isPossible(int maxTarget, int k, vector<int> &arr){
        int currSplit = 1;
        int currSum = 0;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] > maxTarget) return false;
            if(currSum + arr[i] > maxTarget){
                currSplit++;
                currSum = arr[i];
                if(currSplit > k){
                    return false;
                }
            }else{
                currSum += arr[i];
            }
        }
        return true;
        

    }
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 1;
        int right = accumulate (nums.begin(), nums.end(),0);
        int ans = 0;
        while(left <= right){
            int mid = left + ((right - left)/2);
            cout<<mid<<endl;

            if(isPossible(mid,k,nums)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }


        }
        return ans;
        
    }
};