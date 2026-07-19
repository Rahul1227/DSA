class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        vector<vector<int>> ans;
        bool inserted = false;
        for(auto interval : intervals){
            int currStart = interval[0];
            int currEnd = interval[1];
            if(inserted){
                ans.push_back(interval);
            }else{
                if(currEnd < newStart){
                    ans.push_back(interval);
                }else if(newEnd < currStart){
                    if(!inserted){
                        inserted = true;
                        ans.push_back({newStart, newEnd});
                    }
                    ans.push_back(interval);
                }else{
                    newStart = min(newStart, currStart);
                    newEnd = max(currEnd, newEnd);
                }
            }



        }

        if(!inserted){
            ans.push_back({newStart, newEnd});
        }

        return ans;
        
    }
};