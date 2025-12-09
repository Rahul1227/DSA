class Solution {
private:
    static bool compare(const vector<int> &a, const vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int n = intervals.size();
        if(n == 1) return 0;

        int count = 0;
        int i =0;
        int j = 1;
        while(j < n){
            int currentEnd = intervals[i][1];
            int nextStart = intervals[j][0];
            int nextEnd = intervals[j][1];
            if(currentEnd <= nextStart){
                i=j;
                j++;
            }else{
                if(currentEnd <= nextEnd){
                    j++;
                    count++;
                }else{
                    i=j;
                    j++;
                    count++;
                }
            }
        }

        return count;
        
        

    }
};