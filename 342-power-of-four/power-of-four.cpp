class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        double logVal = log2(n) / 2;
        return floor(logVal) == logVal;
        
    }
};