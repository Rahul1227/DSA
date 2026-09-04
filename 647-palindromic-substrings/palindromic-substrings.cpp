class Solution {
private:
    int getCount(int i,int j, string &s){
        // using expand around the center
        int n = s.size();
        int count = 0;
        while(i>=0 && j<n){
            if(s[i] == s[j]){
                count++;
                i--;
                j++;
            }else{
                return count;
            }
        }

        return count;
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;  i<s.size(); i++){
            ans += getCount(i,i,s);
            ans += getCount(i,i+1,s);
        }
        return ans;
        
    }
};