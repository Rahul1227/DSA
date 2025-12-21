class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int len = strs[0].size();
        int n = strs.size();
        vector<bool> isSorted(n-1, false);

        int count =0;
        for(int col =0; col < len; col++){
            vector<int> temp;
            for(int row =0; row < n-1; row++){
                if(isSorted[row]) continue;

                if(strs[row][col] < strs[row+1][col]){
                    temp.push_back(row);
                }else if(strs[row][col] > strs[row+1][col]){
                    temp.clear();
                    count++;
                    break;
                }
               
            }
            for(auto it : temp){
                isSorted[it] = true;
            }
        }

        return count;
        
    }
};