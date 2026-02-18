class Solution {
public:
    bool hasAlternatingBits(int n) {
        int oneCount = __builtin_popcount(n);

        for(int i =0; i<31; i++){
            if(oneCount < 1) break;
            int lastBit = n & 1<<i;
            lastBit = lastBit>>i;
            int secondLastBit = n & 1<<(i+1);
            secondLastBit = secondLastBit>>(i+1);
            // cout<<"the last bit "<<lastBit<<endl;
            // cout<<"the second last bit "<<secondLastBit<<endl;
            if(lastBit == secondLastBit) return false;
            if(i == 0 && lastBit == 1){
                oneCount--;
            }

            if(secondLastBit == 1){
                oneCount--;
            }
        }

        return true;
        
    }
};