class NumArray {
private:
    vector<int> segmentTree;
    int n;

    void buildTree(int ind, int left, int right, vector<int> &nums){
        if(left == right){
            segmentTree[ind] = nums[left];
            return;
        }

        int mid = left + ((right -left)/2);
        buildTree(2 * ind + 1 , left, mid, nums);
        buildTree(2 * ind + 2, mid +1, right, nums);
        segmentTree[ind] = segmentTree[2 * ind +1] + segmentTree[2 * ind + 2];
    }

    void updateTree(int ind, int left, int right, int targetInd, int val){
        if(left == right){
            segmentTree[ind] = val;
            return;
        }

        int mid = left + ((right - left)/2);
        if(targetInd <= mid){
            updateTree(2 * ind + 1, left, mid, targetInd, val);
        }else{
            updateTree(2 * ind + 2, mid + 1, right, targetInd, val);
        }

        segmentTree[ind] = segmentTree[2*ind+1] + segmentTree[2*ind+2];
    }

    int getRangeSum(int ind, int left, int right, int targetLeft, int targetRight){
        // completely out-of range
        if(left > targetRight || right < targetLeft){
            return 0;
        }

        // completely inside the range
        else if(left >= targetLeft && right <= targetRight){
            return segmentTree[ind];
        }

        else{
            int mid = left + (( right - left)/2);

            return getRangeSum(2 * ind +1, left, mid, targetLeft, targetRight) + 
                   getRangeSum(2 * ind + 2, mid+1, right, targetLeft, targetRight);
        }
    }
public:
    NumArray(vector<int>& nums) {
        n =nums.size();
        segmentTree.resize(4*n,0);
        // ind, left, right, nums
        buildTree(0,0, n-1, nums);
        
    }
    
    void update(int index, int val) {
        // ind, left, right, targetInd, val
        updateTree(0,0,n-1,index, val);
        
    }
    
    int sumRange(int left, int right) {
        return getRangeSum(0,0,n-1,left, right);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */