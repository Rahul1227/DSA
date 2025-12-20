class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count  = 0;
        int  len = strs[0].size();
        int n = strs.size();

        for(int j =0; j< len; j++){
            for(int i=0; i<n-1; i++){
                if(strs[i][j]-'0' > strs[i+1][j] - '0'){
                    count++;
                    break;
                }
            }
        }

        return count;
        

    }
};