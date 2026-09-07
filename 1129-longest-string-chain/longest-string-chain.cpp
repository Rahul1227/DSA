class Solution {
private:
    static bool compare(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    bool isPossible(string& s1, string& s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n2 != n1 + 1)
            return false;
        int k = 1;
        int i = 0;
        int j = 0;
        while (i < n1) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                if (k) {
                    k--;
                    j++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    int solve(int ind, int prevInd, vector<vector<int>>& dp,
              vector<string>& words) {
        // base case
        if (ind == words.size()) {
            return 0;
        }

        if (dp[ind][prevInd + 1] != -1)
            return dp[ind][prevInd + 1];

        int notTake = solve(ind + 1, prevInd, dp, words);

        int take = 0;

        if (prevInd == -1 || isPossible(words[prevInd], words[ind])) {
            take = 1 + solve(ind + 1, ind, dp, words);
        }

        return dp[ind][prevInd + 1] = max(take, notTake);
    }

public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);

        // for (auto& it : words) {
        //     cout << it << " ";
        // }
        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, dp, words);
    }
};