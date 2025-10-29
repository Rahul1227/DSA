class Solution {
public:
    int hammingWeight(int n) {
        int counter = 0;
        while(n){
            int mask = n & -n;
            n = n - mask;
            counter++;
        }

        return counter;
        
    }
};