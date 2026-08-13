class Solution {
private:
    int getCount(int i, int j, string &s){
        int n = s.size();
        int count = 0;

        while(i>=0 && j< n && s[i] == s[j]){
            count++;
            // ulta hai 
            i--;
            j++;
        }

        return count;
    }
public:
    int countSubstrings(string s) {
        int ans = 0;

        for(int i=0; i<s.size(); i++){
            // odd len
            ans += getCount(i,i,s);

            // even len
            ans += getCount(i, i+1, s);

        }

        return ans;
        
    }
};