class Solution {
private:
    // bool solve(string &s, int ind, int count){
    //     if (ind == s.size()) return count == 0;

    //     if (s[ind] == '(') {
    //         return solve(s, ind+1, count+1);
    //     }
    //     else if (s[ind] == ')') {
    //         if (count == 0) return false;
    //         return solve(s, ind+1, count-1);
    //     }
    //     else { // '*'
    //         bool open = solve(s, ind+1, count+1);           // treat '*' as '('
    //         bool close = (count > 0) && solve(s, ind+1, count-1); // treat '*' as ')'
    //         bool empty = solve(s, ind+1, count);            // treat '*' as empty
    //         return open || close || empty;
    //     }
    // }
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;
        for(auto c : s ){
            if(c == '('){
                min++;
                max++;
            }else if (c == ')'){
                if(min > 0) min--;
                max--;

            }else{
                if(min > 0) min --;
                max++;
            }
             if(max < 0) return false;
        }

       
        return min == 0;
    }
};
