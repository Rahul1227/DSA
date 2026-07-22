class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }

        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);

        int count = 0;
        int i = 0;
        int j = 0;
        int n = points.size();
        while(i<n){
            int windowStart = points[i][0];
            int windowEnd = points[i][1];

            while(j<n && points[j][0] <= windowEnd && points[j][1] >= windowStart){
                windowStart = max(windowStart, points[j][0]);
                windowEnd = min(windowEnd, points[j][1]);
                j++;
            }
            count++;
            i =j;
            j++;
        }

        return count;
        
    }
};