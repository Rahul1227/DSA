class Solution {
public:
    int maxDepth(string s) {
        int maxCount = 0;
        int count = 0;
        for(auto c : s){
            if(c == '('){
                count++;
                maxCount = max(maxCount, count);
            }
            if( c== ')'){
                count--;
            }
        }
        return maxCount;
        
    }
};