class Solution {
private:
    void solve(int ind, long long currVal, long long preVal, string &curr, vector<string> &ans, string &num, int target){
        int n = num.size();
        if(ind == n){
            if(currVal == target){
                ans.push_back(curr);
            }
            return;
        }

        string runningStr = "";
        long long runningVal = 0;

        for(int i=ind; i<n; i++){
            runningStr += num[i];
            runningVal = runningVal * 10 + num[i] - '0';

            if(runningStr.size() > 1 && runningStr[0] == '0') break;

            if(ind == 0){
                curr += runningStr;
                solve(i + 1, runningVal, runningVal, curr, ans, num, target);
                curr.resize(curr.size() - runningStr.size());
            }else{
                // addition
                curr += '+' + runningStr;
                solve(i + 1, currVal + runningVal, runningVal, curr, ans, num, target);
                curr.resize(curr.size() - runningStr.size() - 1);

                // subtraction
                curr += '-' + runningStr;
                solve(i + 1, currVal - runningVal, -runningVal, curr, ans, num, target);
                curr.resize(curr.size() - runningStr.size() - 1);

                // multiplication
                curr += '*' + runningStr;
                solve(i + 1, (currVal - preVal) + preVal * runningVal, preVal * runningVal, curr, ans, num, target);
                curr.resize(curr.size() - runningStr.size() - 1);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string curr;
        solve(0, 0LL, 0LL, curr, ans, num, target);
        return ans;
    }
};