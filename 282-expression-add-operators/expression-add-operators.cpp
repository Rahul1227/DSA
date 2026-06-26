class Solution {
private:
    void solve(int ind, long long currVal, long long lastVal, string& curr,
               vector<string>& ans, string& num, int target) {
        if (ind == num.size()) {
            if (currVal == target) ans.push_back(curr);
            return;
        }

        long long num_val = 0;
        for (int i = ind; i < num.size(); i++) {
            num_val = num_val * 10 + (num[i] - '0');
            string token = num.substr(ind, i - ind + 1);

            // no leading zeros: "05", "01" not allowed
            if (token.size() > 1 && token[0] == '0') break;

            if (ind == 0) {
                curr += token;
                solve(i + 1, num_val, num_val, curr, ans, num, target);
                curr.resize(curr.size() - token.size());
            } else {
                curr += '+' + token;
                solve(i + 1, currVal + num_val, num_val, curr, ans, num, target);
                curr.resize(curr.size() - token.size() - 1);

                curr += '-' + token;
                solve(i + 1, currVal - num_val, -num_val, curr, ans, num, target);
                curr.resize(curr.size() - token.size() - 1);

                curr += '*' + token;
                solve(i + 1, currVal - lastVal + lastVal * num_val, lastVal * num_val, curr, ans, num, target);
                curr.resize(curr.size() - token.size() - 1);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string curr = "";
        solve(0, 0, 0, curr, ans, num, target);
        return ans;
    }
};