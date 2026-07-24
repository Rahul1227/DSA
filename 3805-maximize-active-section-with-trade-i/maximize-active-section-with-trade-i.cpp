class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = count(s.begin(), s.end(), '1');
        vector<int> inactiveSections;
        int i = 0;
        int n = s.size();
        while(i<n){
            if(s[i] == '0'){
                int start = i;
                while(i<n && s[i] == '0'){
                    i++;
                }
                inactiveSections.push_back(i-start);
            }else{
                i++;
            }

        }

        int maxExtra = 0;
        for(int i=1; i< inactiveSections.size(); i++){
            maxExtra = max(maxExtra, inactiveSections[i] + inactiveSections[i-1]);
        }
        return maxExtra + ones;
        
    }
};