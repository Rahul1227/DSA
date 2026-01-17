class NumArray {
    vector<int> segTree;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4 * n, 0);
        buildTree(0,0,n-1,nums);
        
    }

    void buildTree(int i, int left, int right, vector<int> &nums){
        //base case
        if(left == right){
            segTree[i] = nums[left];
            return;
        }

        int mid = left + ((right - left)/2);
        buildTree(2 * i + 1, left , mid, nums);
        buildTree(2 * i + 2, mid + 1, right, nums);

        segTree[i] = segTree[2 * i +1] + segTree[2 *i +2];

    }

    void updateVal(int i, int left, int right, int index, int val){
        //base case
        if(left == right){
            segTree[i] = val;
            return;
        }

        int mid = left + ((right -left)/2);

        if(index <= mid){
            updateVal(2 * i +1, left, mid, index, val);
        }else{
            updateVal(2*i  +2, mid+1, right, index, val);
        }

        segTree[i] = segTree[2 * i +1] + segTree[2 * i + 2];
    }
    
    void update(int index, int val) {
        updateVal(0,0,n-1, index, val);
        
    }

    int getSum(int i, int left, int right, int start, int end){
        if(left > end || right < start){
            return 0;
        }else if(left >= start && right <= end){
            return segTree[i];
        }else{
            int mid = left + ((right - left)/2);
            int leftSum = getSum(2*i+1, left, mid, start, end);
            int rightSum = getSum(2*i+2, mid+1,right, start, end);
            return leftSum + rightSum;
        }
    }
    
    int sumRange(int left, int right) {

        return getSum(0,0,n-1, left, right);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */