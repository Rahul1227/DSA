class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1005, 0);
        
        for(auto trip: trips){
            int num = trip[0];
            int from = trip[1];
            int to = trip[2];
            diff[from] += num;
            diff[to] -=num;
        }

        int currSum =0;
        for(int i=0; i<1005; i++){
            currSum += diff[i];
            if(currSum > capacity) return false;
        }

        return true;

        
    }
};