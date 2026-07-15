class Solution {
private:
    int getGCD(int a, int b){
        if(b == 0) return a;
        return getGCD(b, a%b);
    }
public:
    int gcdOfOddEvenSums(int n) {
        int range = 2*n;
        int oddSum = 0;
        int evenSum = 0;
        for(int i =1; i<=range; i++){
            if(i%2 != 0){
                oddSum += i;
            }else{
                evenSum += i;
            }
        }

        return getGCD(oddSum, evenSum);
        
    }
};