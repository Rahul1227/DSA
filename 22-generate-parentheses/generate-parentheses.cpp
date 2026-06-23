class Solution {
private:
    void solve(int OC, int CC, int n, string &curr, vector<string>& ans) {
        if (OC > n || CC > n)
            return;
        if (OC == n && CC == n) {
            ans.push_back(curr);
            return;
        }

        curr.push_back('(');
        solve(OC + 1, CC, n, curr, ans);
        curr.pop_back();

        if (OC > CC) {
            curr.push_back(')');
            solve(OC, CC + 1, n, curr, ans);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        solve(0, 0, n, curr, ans);
        return ans;
    }
};