class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int maxPop = 0;
        int currPop = 0;
        int year;
        vector<int> diff(2051);
        for(auto log: logs){
            int birth = log[0];
            int death = log[1];
            diff[birth]++;
            diff[death]--;
        }

        for(int i=0; i<2051; i++){
            currPop += diff[i];
            if(currPop > maxPop){
                maxPop = currPop;
                year = i;
            }
        }
        return year;
        
    }
};