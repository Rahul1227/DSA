class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0;
        int totalfuel = 0;
        int totalgas = accumulate(gas.begin(), gas.end(), 0);
        int totalcost = accumulate(cost.begin(), cost.end(), 0);
        if(totalcost > totalgas) return -1;
        for(int i =0; i< gas.size()-1; i++){
            totalfuel += gas[i];
            totalfuel -= cost[i];           
            if(totalfuel < 0){
                ans = i+1;
                totalfuel = 0;
            } 
           
            
        }

        return ans;
        
    }
};