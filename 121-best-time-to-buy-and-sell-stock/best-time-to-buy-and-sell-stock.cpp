class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int costPrice = INT_MAX;
        int maxProfit = 0;
        int n = prices.size();
        for(int i=0; i<n; i++){
            if(prices[i] < costPrice){
                costPrice = prices[i];
            }else{
                maxProfit = max(maxProfit, prices[i] - costPrice);
            }
        }

        return maxProfit;
    }
};