class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int targetStart = newInterval[0];
        int targetEnd = newInterval[1];
        bool placed = false;

        for(int i =0; i<intervals.size(); i++){
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            if(placed || currEnd < targetStart){
                ans.push_back({currStart, currEnd});
            }else{
                if(currEnd >= targetStart && currStart <= targetEnd){
                    targetStart = min(targetStart, currStart);
                    targetEnd = max(targetEnd, currEnd);

                }else{
                    ans.push_back({targetStart, targetEnd});
                    placed = true;
                    ans.push_back({currStart, currEnd});
                }
            }
        }
        if(!placed){
            ans.push_back({targetStart, targetEnd});
        }

        return ans;
        
    }
};