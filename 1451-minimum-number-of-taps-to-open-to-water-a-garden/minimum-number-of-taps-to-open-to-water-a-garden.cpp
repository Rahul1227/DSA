class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> intervals(n+1);
        for(int i =0; i<ranges.size(); i++){
            int startPoint = max(0, i - ranges[i]);
            int endPoint = min(n, i+ranges[i]);
            intervals[startPoint] = max(intervals[startPoint], endPoint);
        }
        int count =0;
        int maxReach = 0;
        int currReach =0;
        
        for(int i =0; i<=n; i++){
           if(i > maxReach) return -1;

            if(i > currReach){
                currReach = maxReach;
                count++;
            }
            maxReach = max(maxReach, intervals[i]);

        }

        return count;
        
    }
};