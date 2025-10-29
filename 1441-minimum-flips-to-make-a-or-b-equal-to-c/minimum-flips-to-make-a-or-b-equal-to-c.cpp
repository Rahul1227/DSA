class Solution {
public:
    int minFlips(int a, int b, int c) {
        int orResult = a | b;
        int andResult = a & b;
        int xorResult = orResult  ^ c;
        int result = 0;
        while(xorResult){
            int lastDigit1 = xorResult & 1;
            int lastDigit2 = andResult & 1;
            if(lastDigit1){
                result = result + lastDigit1 + lastDigit2;
            }
            xorResult = xorResult >> 1;
            andResult = andResult >>1;
        }

        return result;
        
    }
};