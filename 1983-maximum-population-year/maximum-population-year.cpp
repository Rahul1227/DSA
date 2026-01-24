class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> event;

        for(auto& log : logs){
            event[log[0]]++;
            event[log[1]]--;
        }

        int maxPopulation = 0;
        int maxPopulationYear = 0;
        int currPopulation = 0;

        for(auto [year, population] : event){
            currPopulation += population;
            if(currPopulation > maxPopulation){
                maxPopulation = currPopulation;
                maxPopulationYear = year;
            }
            
        }

        return maxPopulationYear;
        
    }
};