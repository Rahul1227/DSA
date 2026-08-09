class Solution {
private:
    vector<int> seg;

    void build(int i, int l, int r, vector<int> &arr){
        if(l==r){
            seg[i] = arr[l];
            return;
        }

        int mid = l + (r-l)/2;
        build(2*i+1,l, mid, arr);
        build(2*i+2, mid+1, r, arr);

        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    void update(int i, int l, int r, int ind, int val){
        if(l == r){
            seg[i] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(ind <= mid){
            update(2*i+1, l, mid, ind, val);
        }else{
            update(2*i+2, mid+1, r, ind, val);
        }

        seg[i] = seg[2*i+1] + seg[2*i+2];
    }


    int getVal(int i, int l, int r, int start, int end){
        if(r < start || l > end){
            return 0;
        }else if(start <= l && r<= end){
            return seg[i];
        }else{
            int mid = l + (r-l)/2;
            return getVal(2*i+1, l, mid, start, end) + getVal(2*i+2, mid+1, r, start, end);

        }
    }

public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        seg.resize(4*n);
        vector<int> isPeak(n, 0);

        for(int i=1; i<n-1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                isPeak[i] = 1;
            }
        }

        build(0,0,n-1, isPeak);

        vector<int> ans;

        for(auto query : queries){
            int code = query[0];
            if(code == 1){
                int l = query[1];
                int r = query[2];
                int res = getVal(0,0,n-1,l+1, r-1);
                ans.push_back(res);
            }else{
                int ind = query[1];
                int val = query[2];
                nums[ind] = val;

                int startInd = max(1, ind-1);
                int endInd = min(n-2, ind+1);

                for(int i=startInd; i<=endInd; i++){
                    int currVal = 0;
                    if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                        currVal = 1;
                    }
                    
                    if(currVal != isPeak[i]){
                        isPeak[i] = currVal;
                        update(0,0,n-1,i, currVal);
                    }
                   
                }
            }
        }



        return ans;
        
    }
};