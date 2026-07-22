class Solution {
public:
    static bool compare(const vector<int> &a, const vector<int> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }

        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        sort(intervals.begin(), intervals.end(), compare);
        int i =0;
        int j = 1;
        while(j < n){
            if(intervals[i][1] > intervals[j][0]){
                if(intervals[i][1] > intervals[j][1]){
                    i=j;
                    // j++;

                }
                // }else{
                //     j++;
                // }
                count++;
            }else{
                i=j;
                // j++;
            }


            // i++;
            j++;
        }

        return count;


        
    }
};