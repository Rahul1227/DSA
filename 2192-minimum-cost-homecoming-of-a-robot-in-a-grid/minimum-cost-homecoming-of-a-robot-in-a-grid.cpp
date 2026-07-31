class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        if(startPos[0] == homePos[0] && startPos[1] == homePos[1]){
            return 0;
        }
        int totalCost = 0;

        int firstRow = startPos[0];
        int lastRow = homePos[0];

        if(lastRow > firstRow){
            for(int i  = firstRow+1; i<= lastRow; i++){
                totalCost += rowCosts[i];
            }
        }else{
            for(int i = firstRow-1; i>= lastRow; i--){
                // cout<<"inside here"<<endl;
                totalCost += rowCosts[i];
            }
        }

        int firstCol = startPos[1];
        int lastCol = homePos[1];

        if(firstCol < lastCol){
            for(int j = firstCol+1; j<= lastCol; j++){
                totalCost += colCosts[j];
            }
        }else{
            for(int j= firstCol-1; j>= lastCol; j--){
                totalCost += colCosts[j];
            }
        }

        return totalCost;
    }
};