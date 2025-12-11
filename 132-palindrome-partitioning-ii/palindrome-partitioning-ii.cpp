class Solution {
private:

    bool isPalindrome(int i, int j, string &s){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }




    int solve(int ind, vector<int> &dp, string &s){
        //base condition
        if(ind == s.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        int minPartition = INT_MAX;

        for(int j = ind; j<s.size(); j++){
            int currPartition = INT_MAX;
            if(isPalindrome(ind,j,s)){
                currPartition = 1 + solve(j+1, dp, s);
            }

            minPartition = min(minPartition, currPartition);
        }

        return dp[ind] = minPartition;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, dp, s) - 1;
        
    }
};