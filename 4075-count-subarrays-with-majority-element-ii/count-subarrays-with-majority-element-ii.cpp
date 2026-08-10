class SegmentTree{
public:
    vector<long long> seg;

    SegmentTree(int n){
        seg.assign(4*n, 0);
    }

    void update(int i, int l, int r, int ind, int val){
        if(l == r){
            seg[i] += val;
            return;
        }

        int mid = l + (r-l)/2;

        if(ind <= mid){
            update(2*i+1, l, mid, ind, val);
        }else{
            update(2*i+2, mid+1, r, ind,val);
        }

        seg[i] = 1LL * seg[2*i+1] + seg[2*i+2];
    }

    long long getVal(int i, int l, int r, int start, int end){
        if(r < start || l > end){
            return 0;
        }else if(start <= l && r<= end){
            return seg[i];
        }else{
            int mid = l + (r-l)/2;
            return 1LL *getVal(2*i+1, l, mid, start, end) + getVal(2*i+2, mid+1, r, start, end);
        }
    }


};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);

        // getting the prefixSum
        for(int i=0; i<n; i++){
            prefixSum[i+1] = prefixSum[i] + (nums[i] == target ? 1: -1);
        }

        set<int> values(prefixSum.begin(), prefixSum.end());

        unordered_map<int,int> mp;
        int rank =0;
        for(auto x: values){
            mp[x] = rank++;

        }

        long long ans;
        SegmentTree st(rank);

        for(int i =0; i<=n; i++){
            int currInd = mp[prefixSum[i]];
            long long val = st.getVal(0,0,rank-1,0,currInd-1);
            ans += val;
            st.update(0,0,rank-1,currInd,1);
        }

        return ans;
        
    }
};