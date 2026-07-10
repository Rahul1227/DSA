class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 1;
        int i =1;
        int n = ratings.size();
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                ans++;
                i++;
                continue;
            }
            int peak = 1;
            while(i<n && ratings[i-1] < ratings[i]){
                peak++;
                ans += peak;
                i++;
            }
            int down = 1;
            while(i<n && ratings[i-1] > ratings[i]){
                ans += down;
                down++;
                i++;
            }

            if(down > peak){
                ans += down - peak;
            }
        }

        return ans;
        
    }
};