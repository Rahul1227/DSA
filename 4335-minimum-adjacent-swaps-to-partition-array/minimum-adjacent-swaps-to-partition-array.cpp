const int MOD = 1e9+7;
class Solution {
private:
    void merge(int i, int mid, int j, vector<int> &arr, long long &ans){
        int l = i;
        int r = mid+1;
        vector<int> temp;
        
        while(l <= mid && r <= j){
            if(arr[l] <= arr[r]){
                temp.push_back(arr[l]);
                l++;
            }else{
                ans = (1LL *ans + (mid - l +1)) % MOD;
                temp.push_back(arr[r]);
                r++;
            }
        }
        
        while(l <= mid){
            temp.push_back(arr[l++]);
            
        }
        
        while(r <= j){
            temp.push_back(arr[r++]);
            
        }
        
        
        for(int z=i; z<=j; z++){
            arr[z] = temp[z-i];
        }
    }
  
  
  
    void solve(int i, int j, vector<int> &arr, long long &ans){
        if(i>=j) return;
        int mid = i + ((j-i)/2);
        solve(i, mid, arr, ans);
        solve(mid+1, j, arr, ans);
        merge(i, mid, j, arr, ans);
    }
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        vector<int> newArr;
        for(auto num: nums){
            if(num < a){
                newArr.push_back(0);
            }else if(num >=a && num<=b){
                newArr.push_back(1);
            }else{
                newArr.push_back(2);
            }
        }

        int n = nums.size();
        long long ans =0;
        solve(0, n-1, newArr, ans);
        return ans;
        
    }
};