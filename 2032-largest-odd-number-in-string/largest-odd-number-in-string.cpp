class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int i = n-1;
        while(i>=0){
            int lastdigit = num[i] -'0';
            if(lastdigit % 2 != 0){
                break;
            }
            i--;
        }

        if(i < 0){
            return "";
        }else{
            return num.substr(0, i+1);
        }
        
    }
};