class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int minLen = INT_MAX;

        for(int i =0; i<n; i++){
            int currLen = strs[i].size();
            minLen = min(currLen, minLen);
        }
        int i,j;
        for(j =0; j<minLen; j++){
            for(i = 1; i<n; i++){
                if(strs[i][j] != strs[i-1][j]){
                    return strs[i].substr(0,j);
                }
            }
        }

        if( j == minLen){
            return strs[0].substr(0,j);
        }else{
            return "";
        }
    }
};