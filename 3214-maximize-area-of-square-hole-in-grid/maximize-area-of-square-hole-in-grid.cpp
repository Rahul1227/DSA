class Solution {
private:
    int getMaxSide(vector<int> & sides){
        int n = sides.size();
        int maxSide = 1;
        sort(sides.begin(), sides.end());
        int curr = 1;
        for(int i =1; i<n; i++){
            if(sides[i] == (sides[i-1] +1)){
                curr++;
            }else{
                maxSide = max(maxSide, curr);
                curr= 1;
            }
        }
        maxSide = max(maxSide, curr) + 1;

        return maxSide;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int height = getMaxSide(vBars);
        int width = getMaxSide(hBars);
        int minSide = min(height, width);
        int area = minSide * minSide;
        return area;
        
    }
};