class NumArray {
public:
    vector<int> bit;
    int n;
    vector<int> arr;

    void updateVal(int ind, int val){
        while(ind <= n){
            bit[ind] += val;
            // last set bit => ind & (-ind)
            ind =ind + (ind & (-ind));
        }
    }

    int getVal(int ind){
        int ans = 0;
        while(ind > 0){
            ans += bit[ind];
            ind -= (ind & (-ind));
        }
        return ans;
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        bit.resize(n+1, 0);
        arr.resize(n+1, 0);
        for(int i=0; i<n; i++){
            updateVal(i+1, nums[i]);
            arr[i+1] = nums[i];
        }
        
    }
    
    void update(int index, int val) {
        updateVal(index+1, val - arr[index+1]);
        arr[index+1] = val;
        
    }
    
    int sumRange(int left, int right) {
        int RightSum = getVal(right+1);
        int LeftSum = getVal(left);
        return RightSum - LeftSum;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */