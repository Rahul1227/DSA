class NumArray {
private:
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n);
        prefixSum[0] = nums[0];

        for(int i =1; i<n; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        
        
    }
    
    int sumRange(int left, int right) {
        int ToSubtract = 0;
        if(left >= 1){
            ToSubtract = prefixSum[left-1];
        }

        return prefixSum[right] - ToSubtract;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */