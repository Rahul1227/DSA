class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int maxSide = 0;
        int n = bottomLeft.size();

        for(int i =0; i<n;  i++){
            for(int j = i+1; j<n; j++){
                int BLx = max(bottomLeft[i][0], bottomLeft[j][0]);
                int BLy = max(bottomLeft[i][1], bottomLeft[j][1]);

                int TRx = min(topRight[i][0], topRight[j][0]);
                int TRy = min(topRight[i][1], topRight[j][1]);

                if(TRx > BLx && TRy > BLy){
                    int width = TRx - BLx;
                    int height = TRy - BLy;
                    int currSide = min(width, height);
                    maxSide = max(maxSide, currSide);
                }
            }
        }

        return 1LL * maxSide * maxSide;
        
    }
};