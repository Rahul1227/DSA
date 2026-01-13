class Solution {
private:
    bool isBottomGreater(double mid, vector<vector<int>> &squares, long long &totalArea){
        long double bottomArea = 0.0;
        for(auto &square : squares){
            int y = square[1];
            int len = square[2];
            int yPlusLen = y + len;
            if(mid >= yPlusLen){
                bottomArea += 1.0L * len * len;
            }else if(mid > y){
                bottomArea += 1.0 * len * (mid - y);
            }

        }

        long double topArea = 1.0 * totalArea - bottomArea;

        if(bottomArea >= topArea) return true;
        return false;

        
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double ans = 1.000;
        long long totalArea = 0;
        double left = INT_MAX;
        double right = INT_MIN;
        for(auto &square : squares){
            int x = square[0];
            int y = square[1];
            int len = square[2];
            totalArea += 1LL * len * len;
            int yPlusLen = y+len;
            left = min(left, (double)y);
            right = max(right, (double)yPlusLen);
        }

        while(right - left > 1e-5){
            double mid = left * 1.0 +((right - left)/2.0);

            if(isBottomGreater(mid, squares, totalArea)){
                ans = mid;
                right = mid;

            }else{
                left = mid;
            }
        }

        return ans;

        
        
    }
};