class Solution {
public:
    int reverse(int x) {
        // int sign = (x < 0)? -1 : 1;
        vector<int> digits;
        while(x){
            int rem = x % 10;
            x = x/10;
            digits.push_back(rem);
        }
        
        long long ans =0;
        for(int i =0; i<digits.size(); i++){
            ans = ans * 10 + digits[i];
            
        }
        // ans  = ans * sign;
        

        if(ans < INT_MIN || ans > INT_MAX){
                return 0;
        }else{
            return ans;
        }

      
        
        
    }
};