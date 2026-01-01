class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for(int i =0; i<n; i++){
            int sum = carry + digits[i];
            if(sum < 10){
                digits[i] = sum;
                carry = 0;
                break;
            }else{
                carry = 1;
                digits[i] = sum % 10;
            }
        }

        if(carry){
            digits.push_back(1);
        }

        reverse(digits.begin(), digits.end());
        return digits;
        
    }
};