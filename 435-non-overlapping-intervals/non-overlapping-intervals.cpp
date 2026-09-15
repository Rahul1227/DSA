class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int currEnd = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < currEnd){
                count++;
                currEnd = min(currEnd, intervals[i][1]);
            }else{
                currEnd = intervals[i][1];
            }
        }

        return count;
        
    }
};