class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long count = 0;
        int i = 0;
        int j = 0;

        while(i<n && j<n){
            if(prices[i] - prices[j] == j-i){
                count += j-i +1;
                j++;
            }else{
                i = j;
                
            }
        }

        return count;
        
    }
};