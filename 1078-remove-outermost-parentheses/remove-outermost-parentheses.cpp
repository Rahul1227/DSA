class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans ="";
        int openBrac = 0;
        for(auto c : s){
            if(c == '('){
                if(openBrac > 0){
                    ans += c;
                }
                openBrac++;
            }else{
                openBrac--;
                if(openBrac >0){
                    ans += c;
                }
                
            }
        }
        return ans;
        
    }
};