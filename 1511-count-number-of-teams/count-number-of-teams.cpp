class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i=1; i<n-1; i++){
            int currEle = rating[i];

            int leftSmaller = 0;
            int leftGreater = 0;
            int rightSmaller = 0;
            int rightGreater = 0;

            // scanning left
            for(int j=0; j<i; j++){
                if(rating[j] < currEle){
                    leftSmaller++;
                }else if(rating[j] > currEle){
                    leftGreater++;
                }
            }

            // scanning right
            for(int j=i+1; j<n; j++){
                if(rating[j] < currEle){
                    rightSmaller++;
                }else if(rating[j] > currEle){
                    rightGreater++;
                }
            }

            ans += leftSmaller * rightGreater;
            ans += leftGreater * rightSmaller;
        }

        return ans;
    }
};