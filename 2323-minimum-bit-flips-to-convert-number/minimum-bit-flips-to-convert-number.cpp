class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;
        int result = 0;
        while(xorResult){
            result++;
            xorResult = xorResult - (xorResult & - xorResult);
        }
        return result;
        
    }
};