class Solution {
private:
    bool isPossible(int i, int j, string &s, unordered_map<char, int> &mp){
        mp[s[j]]++;
        int toMatchWith = mp[s[j]];
        for(auto &[key, val] :mp){
            if(val != toMatchWith) return false;

        }

        return true;
    }
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 1;
        for(int i =0; i<n; i++){
            unordered_map<char, int> mp;
            for(int j =i; j<n; j++){
                if(isPossible(i,j,s, mp)){
                    int currLen = j-i+1;
                    maxLen = max(maxLen, currLen);

                }
            }
        }

        return maxLen;
    }
};