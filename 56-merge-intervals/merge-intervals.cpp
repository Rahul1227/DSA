class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int i =0;
        int j = i+1;
        int startTime = intervals[i][0];
        int endTime = intervals[i][1];

        while(i<n){
            while(j<n && intervals[j][0] <= endTime){
                endTime = max(endTime, intervals[j][1]);
                j++;
            }
            ans.push_back({startTime, endTime});
            i = j;
            if(i < n){
                startTime = intervals[i][0];
                endTime = intervals[i][1];
            }
            
            j++;

        }

        return ans;
        
    }
};