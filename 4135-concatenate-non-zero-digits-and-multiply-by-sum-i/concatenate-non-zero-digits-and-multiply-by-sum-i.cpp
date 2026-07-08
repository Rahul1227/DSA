class Solution {
public:
    long long sumAndMultiply(int n) {
        string digits ="";
        long long sum = 0;
        while(n){
            int digit = n%10;
            if(digit > 0){
                digits += to_string(digit);
                sum += digit;
            }
            n = n/10;
        }
        if(digits.size() == 0) return 0;

        reverse(digits.begin(), digits.end());
        long long num = stoi(digits);
        return 1LL * num * sum;
        
    }
};