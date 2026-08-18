class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return 0;

        double logVal = log(n) / log(3);
        return abs(logVal - round(logVal)) < 1e-10;
    }
};