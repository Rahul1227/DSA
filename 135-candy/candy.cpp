class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> forwardPass(n, 1);
        vector<int> backwardPass(n,1);

        // forward pass
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                forwardPass[i] = forwardPass[i-1]+1;
            }
        }

        // backward pass
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                backwardPass[i] = backwardPass[i+1] +1;
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans += max(forwardPass[i], backwardPass[i]);
        }

        return ans;
        
    }
};