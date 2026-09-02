class SegmentTree{
private:
    vector<long long> seg;
public:
    SegmentTree(int n){
        seg.resize(4*n, 0);
    }

    long long getVal(int i, int l, int r, int start, int end){
        if(r < start || l > end){
            return 0;
        }else if(start <= l && r <= end){
            return seg[i];
        }else{
            int mid = l + (r-l)/2;
            return getVal(2*i+1, l, mid, start, end) + getVal(2*i+2,mid+1, r, start, end);
        }
    }

    void update(int i, int l, int r, int targetInd){
        if(l == r){
            seg[i] = 1LL * seg[i]+ 1;
            return;
        }
        int mid = l + (r-l)/2;
        if(targetInd <= mid){
            update(2*i+1, l, mid, targetInd);
        }else{
            update(2*i+2, mid+1, r, targetInd);
        }

        seg[i] = 1LL * seg[2*i+1] + seg[2*i+2];
    }




};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);
        for(int i=0; i<n; i++){
            prefixSum[i+1] = prefixSum[i] + (nums[i] == target ? 1 : -1);

        }

        set<int> values(prefixSum.begin(), prefixSum.end());
        int rank =0;
        unordered_map<int,int> mp;

        for(auto it : values){
            mp[it] = rank++;
        }

        // we need to be careful that the set and segment tree don;t share the same name
        SegmentTree st(rank);
        long long ans = 0;
        for(int i=0; i<=n; i++){
            int currInd = mp[prefixSum[i]];
            ans += st.getVal(0,0,rank,0,currInd-1);
            st.update(0,0,rank,currInd);
        }

        return ans;



        
    }
};