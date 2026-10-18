class SegmentTree{
    private:
        vector<int> seg;
    
    public:
        SegmentTree(int n){
            seg.assign(4*n, 0);
        }

    void insertEle(int i, int l, int r, int ind){
        if(l == r){
            seg[i]++;
            return;
        }

        int mid = l + (r - l)/2;

        if(ind <= mid){
            insertEle(2*i+1, l, mid, ind);
        }else{
            insertEle(2*i+2, mid+1, r, ind);
        }

        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    int getSum(int i, int l, int r, int start, int end){
        if(r < start || l > end){
            return 0;
        }else if(start <=l && r<= end){
            return seg[i];
        }else{
            int mid = l + (r - l)/2;
            return getSum(2*i+1, l, mid, start, end) + getSum(2*i+2, mid+1, r, start, end);
        }
        
    }
};


class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        // Your Logic Here
        int n = nums.size();
        // stage 1-> coordinate compression
        set<int> compressSt;
        for(auto num: nums){
            compressSt.insert(num);
        }
        int rank = 0;
        unordered_map<int,int> mp;

        for(auto it: compressSt){
            mp[it] = rank;
            rank++;
        }

        SegmentTree st1(rank);
        SegmentTree st2(rank);

        vector<int> arr1;
        vector<int> arr2;
        int left = 0;
        int right = rank-1;
        arr1.push_back(nums[0]);
        st1.insertEle(0,left, right,mp[nums[0]]);

        arr2.push_back(nums[1]);
        st2.insertEle(0,left, right, mp[nums[1]]);

        for(int i=2; i<n; i++){
            int currInd = mp[nums[i]];

            bool insertFirst = true;
            bool insertSecond = false;
            
            int firstCount = st1.getSum(0, left, right, currInd+1,right);
            int secondCount = st2.getSum(0, left, right, currInd+1,right);

            
            // firstCheck
            if(secondCount > firstCount){
                insertFirst = false;
                insertSecond = true;
            }else if(secondCount == firstCount){
                int len1 = arr1.size();
                int len2 = arr2.size();

                if(len2 < len1){
                    insertFirst = false;
                    insertSecond = true;
                }
            }


            if(insertFirst){
                arr1.push_back(nums[i]);
                st1.insertEle(0, left, right, currInd);
            }else if(insertSecond){
                arr2.push_back(nums[i]);
                st2.insertEle(0, left, right, currInd);
            }

        }

        for(auto num: arr2){
            arr1.push_back(num);
        }






        return arr1;
        
    }
};