class Solution {
private:
    static bool compare(const vector<int> &a, const vector<int> &b){
        if(a[0] == b[0]) return a[1]>b[1];
        else{
            return a[0] < b[0];
        }
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0], intervals[0][1]});
        for(int i =1; i< intervals.size(); i++){
            if(intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }else{
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
            
        }

        return ans;
        

        
    }
};