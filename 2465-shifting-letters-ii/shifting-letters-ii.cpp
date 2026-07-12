class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int size = 5e4 + 4;
        vector<int> diff(size, 0);
        int startInd = size;
        int endInd = 0;

        for(auto shift : shifts){
            int start = shift[0];
            int end = shift[1];
            int val = shift[2] == 1? 1: -1;
            startInd = min(start, startInd);
            endInd = max(endInd, end);
            diff[start] += val;
            diff[end+1] -= val;
        }
        int currSum =0;
        for(int i=startInd; i<=endInd; i++){
            currSum += diff[i];
            int val = (((s[i] - 'a') + currSum) % 26);
            if(val < 0){
                val += 26;
            }
            // cout<<(((s[i] - 'a') + currSum) % 26)<<" ";
            s[i] = val + 'a'; 

        }
        return s;
        
    }
};