class NumArray {
public:
    vector<int> seg;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        buildTree(0, 0, n - 1, nums);
    }

    void buildTree(int i, int l, int r, vector<int>& nums) {
        // base case
        if (l == r) {
            seg[i] = nums[l];
            return;
        }

        int mid = l + ((r - l) / 2);

        // leftSubTree
        buildTree(2 * i + 1, l, mid, nums);

        // right Sub tree
        buildTree(2 * i + 2, mid + 1, r, nums);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    void updateTree(int i, int l, int r, int index, int val) {
        // base case
        if (l == r) {
            seg[i] = val;
            return;
        }

        int mid = l + ((r - l) / 2);

        if (index <= mid) {
            updateTree(2 * i + 1, l, mid, index, val);
        } else {
            updateTree(2 * i + 2, mid + 1, r, index, val);
        }

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    void update(int index, int val) { updateTree(0, 0, n - 1, index, val); }

    int getSum(int i, int l, int r, int start, int end) {
        if (r < start || l > end) {
            return 0;
        } else if (start <= l && r <= end) {
            return seg[i];

        } else {
            int mid = l + ((r - l) / 2);
            return getSum(2 * i + 1, l, mid, start, end) +
                   getSum(2 * i + 2, mid + 1, r, start, end);
        }
    }

    int sumRange(int left, int right) {
        return getSum(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */