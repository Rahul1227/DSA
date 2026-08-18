class Solution {
public:
    bool isPowerOfTwo(int n) {
        double res = 1.0000000  * (log(n)) / log(2);
        // cout<<res;
        return abs(res - round(res)) < 1e-10;
        
    }
};