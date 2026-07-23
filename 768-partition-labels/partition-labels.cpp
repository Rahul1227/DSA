class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastInd(26, -1);
        for(int i =0; i< s.size(); i++){
            lastInd[s[i]-'a'] = i;
        }
        vector<int> ans;
        int maxInd = 0;
        int start = 0;
        for(int i =0; i<s.size(); i++){
            maxInd = max(maxInd, lastInd[s[i] -'a']);
            if(i == maxInd){
                ans.push_back(maxInd-start+1);
                start = i+1;
            }
           
        }

        return ans;
        
    }
};