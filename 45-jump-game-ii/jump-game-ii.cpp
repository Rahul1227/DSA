class Solution {
public:
    int jump(vector<int>& nums) {
         int n = nums.size();
        vector<pair<int,int>> ranges;
        for(int i =0; i<n; i++){
            if(nums[i] == 0) continue;
            int start = i;
            int end = min(n, i+nums[i]);
            ranges.push_back({start, end});

        }

        sort(ranges.begin(), ranges.end());

        int currEnd = 0;
        int target = n-1;
        int jumps = 0;
        int i =0;
        while(currEnd < target){
            if(i >= ranges.size()) return false;

            if(ranges[i].first > currEnd) return false;

            int maxRange = currEnd;
            while( i< ranges.size() && ranges[i].first <= currEnd){
                maxRange = max(maxRange, ranges[i].second);
                i++;
            }

            if(maxRange == currEnd){
                return false;
            }

            currEnd = maxRange;
            jumps++;
        }

        return jumps;
        
    }
};