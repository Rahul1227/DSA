class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // better solution
        vector<int> diff(1001, 0);
        for(auto trip : trips){
            int num = trip[0];
            int from = trip[1];
            int to = trip[2];
            diff[from] += num;
            diff[to] -=num;
        }

        int currPass = 0;
        for(auto num: diff){
            currPass +=  num;
            if(currPass > capacity){
                return false;
            }
        }
        return true;
        



        // O(nlogn)
        // map<int,int> events;
        // for(auto trip : trips){
        //     int num = trip[0];
        //     int from = trip[1];
        //     int to = trip[2];
        //     events[from] += num;
        //     events[to] -=num;
        // }

        // int currPassenger = 0;
        // for(auto [key, val] : events){
        //     currPassenger += val;
        //     if(currPassenger > capacity){
        //         return false;
        //     }
        // }

        // return true;
        
    }
};