class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0;
        int currVal = 0;
        for(auto c: s){
            if(c =='('){
                currVal +=2;
                if(currVal %2 == 1){
                    ans++;
                    currVal--;
                }
            }else{
                currVal--;
                if(currVal < 0){
                    ans++;
                    currVal += 2;
                }
            }
        }

        ans += abs(currVal);
        return ans;
        
    }
};