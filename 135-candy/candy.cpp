class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 1;
        int i = 1;
        int n = ratings.size();
        while(i<n){
            // handling the flat surface
            if(ratings[i] == ratings[i-1]){
                ans++;
                i++;
                continue;
            }
            // for the peak;
            int peak = 1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                ans += peak;
                i++;
            }

            // for the down
            int down = 1;
            while(i<n && ratings[i] < ratings[i-1]){
                
                ans += down;
                down++;
                i++;
            }

            // adding the down difference
            if(down > peak){
                ans += down - peak;
            }

        }

        return ans;
        
    }
};