class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyingPrice = INT_MAX;
        int maxProfit = 0;
        int n = prices.size();

        for(int i =0; i<n; i++){
            if(prices[i] < buyingPrice){
                buyingPrice = prices[i];
                continue;
            }

            maxProfit = max(maxProfit, prices[i] - buyingPrice);
        }

        return maxProfit;
        
    }
};