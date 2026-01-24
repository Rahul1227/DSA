class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        unordered_map<int,int> event;

        for(auto& log : logs){
            event[log[0]]++;
            event[log[1]]--;
        }

        int maxPopulation = 0;
        int maxPopulationYear = 0;
        int currPopulation = 0;

        for(int year = 1950; year<= 2050; year++){
            if(event.count(year)){
                int population = event[year];
                currPopulation += population;
                if(currPopulation > maxPopulation){
                    maxPopulation = currPopulation;
                    maxPopulationYear = year;
                }
            }
        }

        return maxPopulationYear;
        
    }
};