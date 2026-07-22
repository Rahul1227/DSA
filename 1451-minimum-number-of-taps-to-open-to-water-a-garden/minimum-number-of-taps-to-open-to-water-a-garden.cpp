class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // int n = ranges.size();
        vector<int> intervals(n+1);
        for(int i =0; i<=n; i++){
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            intervals[start] = max(intervals[start], end);
        }

        int currEnd = 0;
        int maxEnd = 0;
        int count =0;

        for(int i=0; i<=n; i++){
            if(i > maxEnd) return -1;

            if(i > currEnd){
                count++;
                currEnd = maxEnd;

            }

            maxEnd = max(maxEnd, intervals[i]);
        }

        return count;
        
    }
};