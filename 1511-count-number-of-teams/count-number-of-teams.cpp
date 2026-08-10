class SegmentTree{
public:
    vector<int> seg;

    void reStart(int n){
        seg.assign(4*n,0);
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
        if(r < start || l  > end){
            return 0;
        }else if(start <=l && r<= end){
            return seg[i];
        }else{
            int mid = l + (r-l)/2;
            return getVal(2*i+1, l, mid, start, end) + getVal(2*i+2, mid+1,r, start, end);
        }
    }
};


class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        int maxEle = *max_element(rating.begin(), rating.end());
        SegmentTree st;
        st.reStart(maxEle+1);
        vector<int> leftSmaller(n, 0);
        vector<int> leftGreater(n, 0);


        for(int i=0; i<n; i++){
            int currEle = rating[i];
            int smaller = st.getVal(0,0,maxEle,0,currEle-1);
            int greater = st.getVal(0,0,maxEle,currEle+1, maxEle);
            leftSmaller[i] = smaller;
            leftGreater[i] = greater;
            st.update(0,0,maxEle,currEle, 1);
        }
        st.reStart(maxEle+1);
        for(int i=n-1; i>=0;i--){
            int currEle = rating[i];
            
            int smaller = st.getVal(0,0,maxEle,0,currEle-1);
            int greater = st.getVal(0,0,maxEle,currEle+1, maxEle);
            ans += smaller * leftGreater[i];
            ans += greater * leftSmaller[i];
            st.update(0,0,maxEle,currEle, 1);

            
        }

        return ans;
        
    }
};