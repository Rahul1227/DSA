class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        int j = 1;
        int n = intervals.size();
        while (i < n) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            while (j < n && currEnd >= intervals[j][0]) {
                currEnd = max(currEnd, intervals[j][1]);
                j++;
            }
            ans.push_back({currStart, currEnd});
            i = j;
        }

        // cout<<"printing something"<<endl;
        return ans;
    }
};