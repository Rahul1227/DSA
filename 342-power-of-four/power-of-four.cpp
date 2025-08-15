class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if (n == 1) return 1;

        for(int i =1;(long long) i * i < n; i++){
            if(pow(4,i) == n) return true;
        }

        return false;
        
    }
};