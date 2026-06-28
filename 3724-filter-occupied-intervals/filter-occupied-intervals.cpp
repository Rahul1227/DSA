class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& intervals,
                                                int freeStart, int freeEnd) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        int j = 1;
        int n = intervals.size();
        // if(n == 1){
        //     return intervals;
        // }
        int currEnd;
        int currStart;
        while (i < n || j < n) {
            currStart = intervals[i][0];
            currEnd = intervals[i][1];

            while (j < n && intervals[j][0] - currEnd <= 1) {
                currEnd = max(currEnd, intervals[j][1]);
                j++;
            }

            if (currEnd < freeStart || currStart > freeEnd) {
                // no overlap, keep as is
                ans.push_back({currStart, currEnd});
            } else {
                // left piece
                if (currStart < freeStart)
                    ans.push_back({currStart, freeStart - 1});
                // right piece
                if (currEnd > freeEnd)
                    ans.push_back({freeEnd + 1, currEnd});
            }

            i = j;
            j++;
        }

        return ans;
    }
};