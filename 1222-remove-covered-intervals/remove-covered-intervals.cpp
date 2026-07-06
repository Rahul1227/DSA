class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int n = intervals.size();
        if(n==1) return 1;
        int ans = n;
        int j = 1;
        int i =0;
        while(j < n){
            // int a = intervals[i][0];
            // int b = intervals[i][1];
            // int c = intervals[j][0];
            // int d = intervals[j][1];
            while(j < n && intervals[i][0] <=intervals[j][0] && intervals[i][1] >= intervals[j][1]){
                ans--;
                cout<<j<<endl;
                cout<<ans<<endl;
                j++;
                // c = intervals[j][0];
                // d = intervals[j][1];
            }
            i =j;
            j++;
        }
        
        return ans;
        
    }
};