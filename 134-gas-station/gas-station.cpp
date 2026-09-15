class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = accumulate(gas.begin(), gas.end(), 0);
        int costSum = accumulate(cost.begin(), cost.end(), 0);
        if(gasSum < costSum) return -1;

        int startInd = 0;
        int totalGas = 0;

        for(int i =0; i< gas.size(); i++){
            totalGas += gas[i];
            if(totalGas < cost[i]){
                totalGas = 0;
                startInd = i+1;
            }else{
                totalGas -= cost[i];
            }
        }

        return startInd;
    }
};