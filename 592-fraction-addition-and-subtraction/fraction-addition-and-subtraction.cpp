class Solution {
private:
    int getGCD(int a, int b){
        int minEle = min(a, b);
        for(int i = minEle; i > 0; i--){
            if((a % i == 0) && (b % i == 0)){
                return i;
            }
        }
        return 1;
    }
public:
    string fractionAddition(string exp) {
        int num = 0, deno = 1;
        int n = exp.size();
        int i = 0;
        bool sign;
        int newNum, newDeno;
        
        while(i < n){
            newNum = 0;
            newDeno = 0;
            sign = true;
            
            // Handle sign at the start of fraction
            if(exp[i] == '+' || exp[i] == '-') {
                sign = (exp[i] == '+');
                if(exp[i] == '-') sign = false;
                i++;
            }
            
            // Parse numerator
            while(i < n && exp[i] != '/'){
                newNum = newNum * 10 + (exp[i] - '0');
                i++;
            }
            if(i < n && exp[i] == '/') i++;
            
            // Parse denominator
            while(i < n && exp[i] != '+' && exp[i] != '-'){
                newDeno = newDeno * 10 + (exp[i] - '0');
                i++;
            }
            
            // Apply sign to numerator
            if(!sign) newNum = -newNum;
            
            // Update fraction: num/deno + newNum/newDeno
            num = num * newDeno + newNum * deno;
            deno = deno * newDeno;
        }
        
        // Handle zero numerator
        if(num == 0) return "0/1";
        
        // Simplify fraction
        int gcd = getGCD(abs(num), deno);
        num /= gcd;
        deno /= gcd;
        
        return to_string(num) + "/" + to_string(deno);
    }
};
