class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyingPrice = prices[0];
        int maxProfit = 0;
        for(int i =1; i<n; i++){
            if(prices[i] < buyingPrice){
                buyingPrice = prices[i];
            }else{
                maxProfit = max(maxProfit , (prices[i] - buyingPrice));
            }
        }
        return maxProfit;
        
    }
};