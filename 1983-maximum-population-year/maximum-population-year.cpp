class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int maxPop = 0;
        int year = 0;
        int currPop = 0;
        vector<vector<int>> events;
        for(auto log : logs){
            int birth = log[0];
            int death = log[1];
            events.push_back({birth, 1});
            events.push_back({death, -1});
        }

        sort(events.begin(), events.end());

        for(int i =0; i<events.size(); i++){
            currPop += events[i][1];
            if(currPop > maxPop){
                maxPop = currPop;
                year = events[i][0];
            }

        }

        return year;
        
    }
};